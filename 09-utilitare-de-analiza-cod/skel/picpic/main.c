#include "imglib.h"


#define COPY 0
#define CONTRAST 1
#define SMOOTH 2
#define BLUR 3
#define SHARPEN 4
#define MEAN_REMOVAL 5
#define EMBOSS 6
#define EDGE 7



int action = -1;
pixel_t inf_limit = 0 , sup_limit = 255;

short filter[10];
short imp, depl; 


// do something with the params 
int read_params(int argc, char* argv[])
{
	short i;
	printf("argc: %d\n", argc);
	if(argc < 4 )
	{
		printf("Usage: %s file_input file_output action [parameters]\n", argv[0]);
		return 1;
	}

	if ( strcmp( argv[3], "copy") == 0 )
		action = COPY;
	else if ( strcmp (argv[3], "contrast") == 0 )
	{
		action = CONTRAST;

		if( argc  > 4)
			sscanf(argv[4], "%hhu", &inf_limit);
		if( argc > 5 )
			sscanf(argv[5], "%hhu", &sup_limit);

	}
	else if ( strcmp(argv[3], "smooth") == 0 ) 
	{
		action = SMOOTH;
		for(i = 0 ; i< 9; i++) filter[i] = 1;	
		imp = 9;
		depl = 0;
	}
	else if (strcmp(argv[3] , "blur") == 0 )
	{
		action = BLUR;
		filter[0]=1; filter[1]=2; filter[2]=1;
		filter[3]=2; filter[4]=4; filter[5]=2;
		filter[6]=1; filter[7]=2; filter[8]=1;
		imp = 16; depl=0;
	}
	else if ( strcmp(argv[3] , "sharpen" ) == 0 )
	{
		action = SHARPEN;
		filter[0]=0; filter[1]=-2;filter[2]=0;
		filter[3]=-2; filter[4]=11; filter[5]=-2;
		filter[6]=0; filter[7]=-2; filter[8]=0;
		imp = 3; depl=0;
	}
	else if ( strcmp( argv[3], "mean_removal") == 0)
	{
		action = MEAN_REMOVAL;
		filter[0]=-1; filter[1]=-1;filter[2]=-1;
		filter[3]=-1; filter[4]=9; filter[5]=-1;
		filter[6]=-1; filter[7]=-1; filter[8]=-1;
		imp = 1; depl=0;
	}
	else if ( strcmp ( argv[3] , "emboss") == 0 )
	{
		action = EMBOSS;
		filter[0]=-1; filter[1]=0;filter[2]=-1;
		filter[3]=0; filter[4]=4; filter[5]=0;
		filter[6]=-1; filter[7]=0; filter[8]=-1;
		imp = 1; depl=127;
	}
	else if (strcmp(argv[3], "edge") == 0 )
		action = EDGE;
	else 
	{
		printf("Unknown action.. exiting.\n");
		return 1;
	}

	return 0;

}

//main
int main(int argc, char* argv[])
{
	
	FILE *fi, *fo; 
	
	if (read_params(argc, argv))
		return 1;	
	
	fi = fopen(argv[1], "rb");
	if( fi == 0 )
	{
		puts("Error reading input file");
		return 1;
	}

	fo = fopen(argv[2], "wb");
	if( fo == 0 )
	{
		puts("Error reading output file");
		return 1;
	}

	image output, img = read_ppm (fi);
	if ( img == NULL )
	{
		puts("Could not read image");
		return 1;
	}

	printf("Width: %d\nHeight: %d\n", img->width, img->height);

	
	switch(action)
	{
		case COPY:
			break;

		case CONTRAST:
			printf("Applying contrast...\n");
			apply_contrast(img, inf_limit, sup_limit);
			break;
		case SMOOTH:
		case BLUR:
		case SHARPEN:
		case MEAN_REMOVAL:
		case EMBOSS:
			printf("Applying filter...\n");
			apply_filter(img, filter, imp, depl);
			break;
		case EDGE:
			printf("Applying edge detection...\n");
			get_image_edges(img);
			break;


	}
	printf("Writing output image...\n");
	write_ppm (fo, img);


	printf("Done.. freeing memory.\n");
	free_img(img);

	fclose(fi);
	fclose(fo);
	return 0;
}