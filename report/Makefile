BASENAME = Training-Thales_Raport-de-activitate
PDF = $(addsuffix .pdf, $(BASENAME))
DVI = $(addsuffix .dvi, $(BASENAME))
TEX = $(addsuffix .tex, $(BASENAME))
LATEX = latex
PDFLATEX = pdflatex

.PHONY: all clean

all: $(PDF)

$(DVI): $(TEX)
	# Twice, so TOC is also updated
	$(LATEX) $<
	$(LATEX) $<

$(PDF): $(TEX)
	# Twice, so TOC is also updated
	$(PDFLATEX) $<
	$(PDFLATEX) $<

clean:
	-rm -f *~ *.aux *.log *.blg *.bbl *.out
