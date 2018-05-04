data = read.csv("q13_data.csv",header = TRUE)


# The predictor vector x.
x1=data[c(1:nrow(data)),"Size"]
x2=data[c(1:nrow(data)),"Bedrooms"]
x3=data[c(1:nrow(data)),"Bathrooms"]
x4=data[c(1:nrow(data)),"Price.SQ.Ft"]

# The response vector y.
y=data[c(1:nrow(data)),"Price"]

z = lm(y~x1+x2+x3+x4)
print(summary(z))

#prediction

# Find price of the house having area = 2501.
a = data.frame(x1=1000,x2=2,x3=2,x4=363)
relation = lm(y~x1+x2+x3+x4)
result <-  predict(relation,a)
print(result)
