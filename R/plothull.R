plothull <- function(data,convex_hull){
  n = length(data)
  X = c(1:n)
  Y = c(1:n)
  for(i in 1:n){
    X[i] = data[[i]][1]
    Y[i] = data[[i]][2]
  }
  m = length(convex_hull)
  Xhull = c(1:m)
  Yhull = c(1:m)
  for(i in 1:m){
    Xhull[i] = convex_hull[[i]][1]
    Yhull[i] = convex_hull[[i]][2]
  }
  total_dataX = c(X,Xhull)
  total_dataY = c(Y,Yhull)
  df = data.frame(total_dataX,total_dataY)
  p = ggplot(df,aes(x=total_dataX,y=total_dataY)) + geom_point(aes(x=total_dataX,y=total_dataY)) + geom_segment(aes(x=total_dataX[n+1], y=total_dataY[n+1], xend=total_dataX[n+m], yend=total_dataY[n+m]), color="blue")
  for(i in 1:m)
  {
    p = p + geom_segment(aes_(x=total_dataX[i+n], y=total_dataY[i+n], xend=total_dataX[i+n+1], yend=total_dataY[i+n+1]), color="blue") + geom_point(aes_(x = total_dataX[i+n],y=total_dataY[i+n]), color ="blue")
  }
  p = p + geom_point(aes_(x = total_dataX[n+m],y=total_dataY[n+m]), color ="blue")
  return(p)
}