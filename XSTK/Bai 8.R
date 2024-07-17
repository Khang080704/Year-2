data04 <- load(file = 'data04.rda')
p0 <- 0.6
n <- length(survey)
f <- survey[survey == 1]
p.hat = length(f)/n



kiemDinhTiLe <- function(x,p0,alpha = 0.05){
  n <- length(x)
  f <- length(x[x == 1])
  p.hat <- f/n
  z0 = (p.hat - p0)/sqrt(n)*sqrt(p0*(1-p0))
  p.value <- 1 - qnorm(z0)
  kl <- ifelse(alpha < p.value, 'Bac bo H0','Chua du co so bac bo H0')
  result <- list(p.value,kl)
  result
}
kiemDinhTiLe(survey,p0 = 0.6, alpha = 0.05)


#---------------------------------Bai 5------------------------------
alpha <- 0.15
result <- binom.test(20,100,p = 0.15)
kl <- ifelse(result$p.value < alpha, 'Bac bo H0', 'Chu du co so bac bo H0')
kl
#---------------------------------Bai 6--------------------------------
data <- read.csv('times.csv',header = T)
attach(data)
names(data)
#Cau a
n <- length(KHTN)
f <- length(KHTN[KHTN > 5])
alpha <- 0.05
result <- binom.test(f,n,p = 0.05)
kl <- ifelse(result$p.value < alpha,'Bac bo H0','Chua du co so')
kl
#Cau b
proptest.geq <- function(f,n, p0, alpha){
  p.hat = f/n
  
}


