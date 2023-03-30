\name{tcc-package}
\alias{tcc-package}
\alias{tcc}
\docType{package}
\title{
  A Jarvis March Package for R using Rcpp
}
\description{
  A package containing a jarvis march function (jarvis_march) to find the convex hull of a set of data points, a function (length_of_hull) to find the length of the convex hull, a function (maximumdist_pair) to find the pair of points on the hull that are connected on the hull and are furthest apart, and a function (maximumdist) to find the distance between the pair of points on the hull that are connected and furthest apart. This package also contains a function in_hull to determine what subset of a given set of points are in the convex hull. It contains a function plothull, this is an R function which plots the data points and outlines the convex hull. All functions apart from plothull use C++ to improve their computational efficiency. 
}
\details{
  The function jarvis_march takes a list of 2-dimensional vectors (points in the plane) as an arguement. It will then find the convex hull of the list and output this in the form (x0,y0,x1,y1) which represent the line segments in the plane connecting the points on the hull. This function uses C++ for faster computation.
  
  The function length_of_hull takes an argument of the same form as the output of the jarvis_march function above. It will then calculate the length of the hull (the sum of the length of the line segments connecting the points), and return this length. This function uses C++ for faster computation. 
  
  The function in_hull takes two arguements, firstly a list of vectors of points in the plane and secondly an arguement of the same form as the output of the jarvis_march function. It will search through the convex hull and output the input points which are in the convex hull. It will return "NONE" if none of the input points are in the hull. This function uses C++ for faster computation. 
  
  The function maximumdist takes an argument of the same form as the output of the jarvis_march function and returns the distance between the pair of points on the hull that are connected and furthest apart. This function uses C++ for faster computation.
  
  The function maximumdist_pair takes an argument of the same form as the output of the jarvis_march function and returns the pair of points on the hull that are connected and furthest apart. This function uses C++ for faster computation.
  
  The function plothull is an R function which takes the full data set and the convex hull output from the jarvis_march function as inputs and then plots the data points and outlines the convex hull. 
}
\author{
Theo Crookes, t.crookes@lancaster.ac.uk

Maintainer: Theo Crookes <theoccrookes@email.com>
}
\references{
}
\keyword{ package }
\seealso{
  Examples of the use of this package can be found on the Jupyter Notebook file linked on GitHub (Insert Link).
}
\examples{
  \dontrun{
     ## Optional simple examples of the most important functions
     ## These can be in \dontrun{} and \donttest{} blocks.   
  }
}
