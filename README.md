# tcc Repository
### A repository containing items for STOR601 Interfacing R and C++ Assessment 

## Contents of the Repository

In this repository you can find the installable R package 'tcc': This R package contains a jarvis_march function, a function to plot the data and convex hull, a function to find the length of the hull, a function to find the points in the hull that are furthest apart, a function to find which points are furthest apart and finally a function to see whether a subset of a given set of points are in the convex hull (and which points). This package uses Rcpp to increase the speed of the functions. More details on the functions are given below.

This repository also contains an R file (Example.R) which contains examples of how this package can be used. 

This repository also contains a jypn file ExamplesOfHowToUse.ipynb which shows these examples to view before having to install the package yourself. 

This repository also contains two more jypn files, which are an implementation of the jarvis march algorithm in C++ and one in Python. There is also a jypn comparing how each of the implementations of the jarvis march function compare with respect to the 5Rs. More details about the 5Rs can be found here: https://prezi.com/view/UFn6tMCwgPK4YHf3VrlH/.

This repository also contains a READ ME.Rd giving a more in depth description of the tcc package. 

## How to Install the Package

To install the package, we can use devtools. Once opening R, ensure we have devtools installed:

> install.packages("devtools")

Then get ready to use devtools: 

> library(devtools)

Then use the following commands: 

> install_github(theo-crookes/STOR601Assessment)

> library(tcc)

## More Information

Here you can find more information about the Jarvis March algorithm: https://en.wikipedia.org/wiki/Gift_wrapping_algorithm

Here you can find more information about the Jarvis March algorithm, that my python implementation took inspiration from: https://algorithmtutor.com/Computational-Geometry/Convex-Hull-Algorithms-Jarvis-s-March/

Here you can find more information about the 5Rs in a presentation: https://prezi.com/view/UFn6tMCwgPK4YHf3VrlH/

Here you can find more information about the 5Rs in a paper: https://www.frontiersin.org/articles/10.3389/fninf.2017.00069/full
