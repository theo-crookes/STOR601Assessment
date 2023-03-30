#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include<cmath>

#include<Rcpp.h>
using namespace Rcpp;

//[[Rcpp::export]]
std::string in_hull(std::vector<std::vector<double>> input_points, std::vector<std::vector<double> > convex_hull_edges) // function to see if a point is in the convex_hull
{
    int n;
    n = convex_hull_edges.size();
    int m;
    m = input_points.size();
    std::string s1 {"The following input points are in the convex hull:"};
    std::string s2 {" NONE"};
    std::string s {}; // this string will be updated if there are any points present
    std::string output_string {}; // this will be updated at the end
    int check {0};
            
    for(int i=0; i<m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if (input_points[i][0] == convex_hull_edges[j][0]) // 
            {
                if (input_points[i][1] == convex_hull_edges[j][1]) // 
                {
                    if(check == 1)
                    {
                        s = s + "," "(" + std::to_string(input_points[i][0]) +"," + std::to_string(input_points[i][1]) + ")" ;
                    }
                    if(check == 0)
                    {
                        check = 1;
                        s = "(" + std::to_string(input_points[i][0]) +"," + std::to_string(input_points[i][1]) + ")" ;
                    }
                } 
                
            }
        }
    }
    
    output_string = s1 + s2; // makes the output say there are NO input points in the hull
    
    if(check == 1) // if this is true, makes the output say which points are in the hull
    {
        output_string = s1 + s; // updates the string to say which points are in the hull
    }
    
    return output_string;    
}
