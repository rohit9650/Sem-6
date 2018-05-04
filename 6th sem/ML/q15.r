library(glmnet)

#Load data
data <- read.csv("q14_data.csv")

my_sigmoid=function(z){
  1/(1+exp(-z))
}



#Predictor variables
X <- as.matrix(data[,c(1,2)])

#Add ones to X
X <- cbind(rep(1,nrow(X)),X)

#Response variable
Y <- as.matrix(data$label)

glmmod <- glmnet(X, y=as.factor(Y), alpha=1, family="binomial")

# Plot variable coefficients vs. shrinkage parameter lambda.
plot(glmmod, xvar="lambda")

print(glmmod)
