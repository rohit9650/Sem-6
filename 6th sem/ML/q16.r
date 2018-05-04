library(neuralnet)

#Load data
data <- read.csv("q14_data.csv")

nn <- neuralnet(data$label~data$score1+data$score2,data=data, hidden=0, 
                rep=2, err.fct="ce", linear.output=FALSE)

#nn$result.matrix

plot(nn)

#prediction when score1 is 84 and score2 is 33
result <- compute(nn,data.frame(84,33))
result

prediction = ifelse(result >= 0.5, 1, 0)
prediction
