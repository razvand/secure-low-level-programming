% Razvan Deaconescu, 2010, razvan.deaconescu@cs.pub.ro
%      based on templates by Mircea Bardac and Vlad Dogaru
%
% pisr.cs.pub.ro.cls - class for GSR lectures

\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{training}[2012/02/10]

\LoadClassWithOptions{beamer}

% uncomment the lines bellow for Romanian Language support
% Use UTF8 file encoding when writing .tex files in Romanian
% Romanian Language support
\usepackage{ucs}
\usepackage[utf8x]{inputenc}
\PrerenderUnicode{ăĂâÂîÎșȘțȚ}
\usepackage[romanian,english]{babel}
\usepackage{hyperref}     % use \url{http://$URL} or \href{http://$URL}{Name}
\hypersetup{
  colorlinks,
  urlcolor=blue
}
\usepackage{underscore}   % underscores need not be escaped
\usepackage{listings}
\usepackage[absolute,overlay]{textpos}
\PreloadUnicodePage{200}

\mode<presentation>
{ \usetheme{AnnArbor}
  \usecolortheme{beaver}}

% Support for including graphics
\usepackage{graphicx}
\DeclareGraphicsExtensions{.pdf,.png,.jpg}

% So that we don't have to declare it a bazillion times
\institute[NN]{S.C. Neo Networking S.R.L.}

% Slide-urile cu mai multe părți sunt marcate cu textul (cont.)
\setbeamertemplate{frametitle continuation}[from second]

% Fix verbatim environment: smaller text size
\let\oldverbatim=\verbatim
\renewenvironment{verbatim}{
  \begin{small}
  \begin{oldverbatim}
  %\vspace*{1em}
}%
{%
  %\vspace*{1em}
  \end{oldverbatim}
  \end{small}
}

% command for specifying TODOs
\newcommand{\todo}[1]{
  \textbf{TODO:} #1 \par
}

% command for formatting file or directory names
\newcommand{\file}[1]{\texttt{#1}}

% command for formatting inline commands
\newcommand{\cmd}[1]{\textbf{\texttt{#1}}}
% command for formatting inline function names
\newcommand{\func}[1]{\textbf{\texttt{#1}}}

% Show contents at every section beginning. Ripped off from manual.
%\AtBeginSection[] % Do nothing for \section*
%{
%  \begin{frame}<beamer>
%    \frametitle{Outline}
%  \tableofcontents[currentsection]
%    \end{frame}
%}
