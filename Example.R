## NOTE: this R script can be used to play around with the tcc package in R. 
## See examples of the jarvis_march function, the plot function, the length_of_hull function
## the in_hull function, the maximumdist function and the maximumdist_pair function.

library(ggplot2)
library(tcc)
x <- list(c(0,0),c(1,1),c(10,10),c(0,10),c(10,0),c(5,6),c(2,5),c(4.7,4.6),c(1.7,3.9),c(12,7),c(3,6,4.6), c(1.7,2.5),c(3.8,6.8),c(1.6,3.8),c(8.6,2.1),c(9.3,3.4),c(7.6,9.7),c(9.6,1.1))
convex_hull_test = jarvis_march(x)

##create a plot:
plothull(x,convex_hull_test)

#find the length of the convex hull:
length_of_hull(convex_hull_test)

y <- list(c(1,1),c(10,10),c(0,10),c(3,5))
##check to see what subset of y are in the hull:
in_hull(y,convex_hull_test)

##find the pair of points that are furthest apart, and the distance they are apart:
maximumdist_pair(convex_hull_test)
maximumdist(convex_hull_test)
