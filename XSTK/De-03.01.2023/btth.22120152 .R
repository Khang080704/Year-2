###################################################
#                                                 #
#     Bai thi thuc hanh Xac Suat Thong Ke 2023    #
#                                                 #
###################################################
# Ho va ten: Pham Gia Khang
# MSSV: 22120152
# Ca: 1
# Nhom: 1


# Cau 1.
# a
data01 <- read.csv('total.csv', header = T)
attach(data01)
names(data01)
ci.mean <- function(x, alpha = 0.05){
  x.bar = mean(x)
  x.sd = sd(x)
  n = length(x)
  epsilon = qnorm(1 - 0.05/2)*x.sd/sqrt(n)
  upper = x.bar + epsilon
  lower = x.bar - epsilon
  cat('Khoang tin cay 95%: [', lower,';',upper,']')
}
binhthuong <- age[KL == 1]
ci.mean(binhthuong,alpha = 0.05)

Phidai <- age[KL == 2]
ci.mean(Phidai,0.05)

ungThu <- age[KL == 3]
ci.mean(ungThu,alpha = 0.05)
# b
fPSAbth <- fPSA[KL == 1]
ci.mean(fPSAbth,0.05)

fPSAPhiDai <- fPSA[KL == 2]
ci.mean(fPSAPhiDai,0.05)

fPSAUngThu <- fPSA[KL == 3]
ci.mean(fPSAUngThu,0.05)
# c
khacbiet.2side <- function(x,y,alpha = 0.01){
  x.bar = mean(x)
  y.bar = mean(y)
  x.sd = sd(x)
  y.sd = sd(y)
  Zo = (x.bar - y.bar)/sqrt(x.sd^2/length(x) + y.sd^2/length(y))
  Z = qnorm(1 - alpha/2)
  ifelse(abs(Zo) > Z,'Bac bo Ho','Chua du co so bac bo H0')
}
phidai <- age[KL == 2]
ungthu <- age[KL == 3]
khacbiet.2side(phidai,ungthu, alpha = 0.01)

# Cau 2.
f <- 20
n <- 100
p.hat <- f/n
p = 0.15
alpha = 0.05

Zo = (p.hat - p)/sqrt(p*(1-p)/n)
z = qnorm(1 - alpha/2)
ifelse(abs(Zo) > z, 'Bac bo H0','Chua du co so bac bo')





