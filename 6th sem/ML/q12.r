#Reading data
data <- read.table(file = "q12_data.txt", sep = ",", header = TRUE)

#Dependent variable
y <- data$Price

#Independent variable
x <- data$Area

# Apply the lm() function.
relation <- lm(y~x)

# Find price of a house with Area 3000 sq units.
a <- data.frame(x = 3000)
result <-  predict(relation,a)
print(result)

#visualization
plot(y,x,col = "blue",main = "Area and Price Regression",
     abline(lm(x~y)),cex = 1.3,pch = 16,xlab = "Area in sq. unit",ylab = "Price in dollar")