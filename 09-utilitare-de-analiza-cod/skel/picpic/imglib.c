#include <math.h>
#include "imglib.h"

image alloc_img (unsigned int width, unsigned int height)
{
	
	image img;
	img = malloc (sizeof (image_t));
	if(img == NULL)
		return NULL;

	img->buf = malloc (width * height * sizeof (pixel_t));
	if ( img->buf == NULL )
		return NULL;

	img->width = width;
	img->height = height;
	
	return img;
}

void free_img (image img)
{
	free (img->buf);
	free (img);
}

void fill_img (image img, pixel_t pixel)
{
	unsigned long i, n;
	n = img->width * img->height;
	for (i = 0; i < n; ++i)
	{
		img->buf[i] = pixel;
	}
}

void fill_img_incr (image img)
{
	unsigned long i, n;
	n = img->width * img->height;
	for (i = 0; i < n; ++i)
	{
		img->buf[i] = i % 255;
	}
}

image read_ppm (FILE * pf)
{
	char buf[PPMREADBUFLEN], *t;
	image img;
	unsigned int w, h, d;
	int r;

	if (pf == NULL)
		return NULL;
	t = fgets (buf, PPMREADBUFLEN, pf);
	if ((t == NULL) || (strncmp (buf, "P5\n", 3) != 0))
		return NULL;
	do
	{				
		/* Px formats can have # comments after first line */
		t = fgets (buf, PPMREADBUFLEN, pf);
		if (t == NULL)
			return NULL;
	}
	while (strncmp (buf, "#", 1) == 0);

	r = sscanf (buf, "%u %u", &w, &h);
	if (r < 2)
		return NULL;
	
	r = fscanf (pf, "%u\n", &d);
	if ((r < 1) || (d != 255))
		return NULL;

	img = alloc_img (w, h);
	if (img != NULL)
	{
		size_t rd ;
		size_t i;
		for (i=0; i < h; i++)
		{
			rd = fread (img->buf + i * w, sizeof (pixel_t), w , pf);
		
			if (rd < w )
			{
				free_img (img);
				return NULL;
			}
		}
			
		return img;
	}
}

void write_ppm (FILE * fd, image img)
{
	unsigned int i, r;
	unsigned long n;

 
	(void) fprintf (fd, "P5\n%d %d\n255\n", img->width, img->height);
	

	for(i = 0; i < img->height; i++ )
	{
		r = fwrite (img->buf + i * img->width, sizeof (pixel_t), img->width, fd);
		if ( r != img->width )
		{
			puts("Error writing image to file");
			return; 
		}

	}
	(void) fflush (fd);

}


void apply_contrast(image img, pixel_t inf, pixel_t sup)
{
	unsigned int ii,jj; 
	int pixel; 

	pixel_t min = img->buf[0], max = img->buf[0];

	
	for( ii=0 ; ii < img->height; ii++)
		for( jj = 0 ; jj< img->width; jj++ )
		{
			if(min < img->buf[ii * img->width + jj] )
				min = img->buf[ii * img->width + jj];
			if( max > img->buf[ii * img->width + jj] )
				max = img->buf[ii * img->width + jj];
		}

	for ( ii=0; ii< img->height; ii++ )
		for( jj=0; jj< img->width; jj++)
		{

			pixel = img->buf[ ii*img->width + jj];

			pixel = (int) ( (sup - inf) * (pixel - min) / (max - min) + inf);

			if( pixel > 255 )
				img->buf[ii * img->width + jj] = 255;
			else if( pixel < 0 )
				img->buf[ii * img->width + jj] = 0;
			else img->buf[ii * img->width + jj] = (pixel_t) pixel;

		}


	return;
}

void apply_filter( image img, short filter[], short imp, short depl )
{
	unsigned int i, j; 
	int pixel ; 

	image new = alloc_img(img->width, img->height);
	if ( new == NULL)
	{	
		printf("Couldnt apply filter. Memory insufficient\n");
		return;
	}

	for ( i=0; i< img->height; i++)
		memcpy(new->buf + i*img->width, img->buf + i * img->width, img->width);
	/*
		for ( j=0; j <  img->width; j++ )
			new->buf[i * img->width  + j] = img->buf[ i * img->width + j];
*/

	for ( i=0; i< img->height; i++)
		for ( j=0; j < img->width; j++ )
		{
			pixel = 0 ;

			pixel  = 	new->buf[i* new->width + j ] * filter[0] ;
			pixel += 	j< new->width-1 ? new->buf[i* new->width + j + 1] * filter[1] : 0 ;
			pixel +=	j< new->width-2 ? new->buf[i* new->width + j + 2] * filter[2] : 0 ;
			pixel +=	i< new->height-1 ? new->buf[(i+1) * new->width + j ] * filter[3] : 0 ;
			pixel +=	i< new->height-1 && j< new->width-1 ? new->buf[ (i+1) *new->width + j+1] * filter[4] : 0 ;
			pixel +=	i< new->height-1 && j< new->width-2 ? new->buf[(i+1) * new->width + j + 2] * filter[5] : 0 ;
			pixel +=	i< new->height-2 ? new->buf[(i+2)*new->width + j ] * filter[6] : 0 ;
			pixel +=	i< new->height-2 && j< new->width-1 ? new->buf[(i+2) * new->width + j + 1 ] *filter[7] : 0  ;
			pixel +=	i< new->height-2 && j< new->width-2 ? new->buf[(i+2) *new->width + j + 2] * filter[8] : 0 ;

			pixel = (pixel / imp) + depl;

			//check to stay in bounds
			if( pixel < 0 ) pixel = 0;
			if( pixel > 255 ) pixel = 255;

			img->buf[ i*img->width + j ] = pixel ; 
		}
			
}

void get_image_edges(image img)
{

	unsigned int i, j; 
	int pixelx, pixely, pixel ; 

	image new = alloc_img(img->width, img->height);

	if ( new == NULL)
	{	
		printf("Couldnt find edges. Memory insufficient\n");
		return;
	}

	for ( i=0; i< img->height; i++)
		memcpy(new->buf + i*img->width, img->buf + i * img->width, img->width);

	for ( i=0; i< img->height; i++)
		for ( j=0; j < img->width; j++ )
		{
			pixelx = 0 ;
			pixely = 0 ;

		   	pixelx += j<img->width-1 && i>0  ? new->buf[(i-1)* img->width + j + 1 ] : 0;
        	pixelx += j<img->width-1 ? new->buf[i* img->width + j +1 ] * 2 : 0;
        	pixelx += j<img->width-1 && i< img->height-1 ? new->buf[(i+1)* img->width + j +1 ] : 0 ;

        	pixelx -= j>0 && i>0 ? new->buf[(i-1)* img->width + j - 1 ] : 0;
        	pixelx -= j>0 ? new->buf[i* img->width + j - 1 ] * 2 : 0;
        	pixelx -= j>0 && i<img->height-1 ? new->buf[(i+1)* img->width + j - 1 ] : 0;

        	pixely += i>0 && j>0 ? new->buf[(i-1)* img->width + j - 1 ] : 0;
        	pixely += i>0 ? new->buf[ (i-1)* img->width + j ] * 2 : 0;
        	pixely += i>0 && j<img->width-1 ? new->buf[(i-1)* img->width + j + 1 ] : 0;

        	pixely -= i< img->height-1  && j>0 ? new->buf[(i+1)* img->width + j - 1 ] : 0 ;
        	pixely -= i< img->height-1 ? new->buf[(i+1)* img->width + j ] * 2 : 0 ;
        	pixely -= i< img->height-1  && j< img->width-1 ? new->buf[(i+1)* img->width + j + 1 ] : 0 ;

        	pixel = sqrt( pixelx*pixelx + pixely*pixely );

        	//reverse not to get the negative
        	pixel = 255 - pixel ;

        	//check to stay in bounds
        	if( pixel > 255 ) pixel = 255;
        	if( pixel < 0 ) pixel = 0;

        	img->buf[i * img->width + j] = pixel;

		}
}