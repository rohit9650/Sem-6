#Reading data
data <- read.table(file = "q13_data.txt", sep = "\t", header = TRUE)

#Dependent variable
y <- data$price

# Apply the lm() function.
model <- lm(y ~ data$sqft + data$bedrooms + data$baths, data = data)
