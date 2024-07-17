soLuongSinhVien <- 40
khoangGiaTri <- 0:10

diemSinhVien <- numeric(soLuongSinhVien)

set.seed(123)
diemSinhVien <- sample(khoangGiaTri, soLuongSinhVien, replace = TRUE)
diemSinhVien
sum <- 0
#Tinh ki vong
for (i in 1:40){
  sum <- sum + diemSinhVien[i]
}
diemSinhVien.bar = sum/length(diemSinhVien)
#Tinh var
sum.var <- 0
for(i in 1:40){
  sum.var <- sum.var + (diemSinhVien[i] - diemSinhVien.bar)^2
}
diemSinhVien.var = sum.var/(length(diemSinhVien) - 1)

#----------------------------------------Bai 2---------------------------------------
#a
sixesn <- function(n){
  ketqua <- any((sample(1:6,n,replace = TRUE)) == 6)
  return(ketqua)
}

#b
play <- function(n,N){
  solanthang <- 0
  sum <- 0
  for(i in 1:N){
    solanthang[i] <- sixesn(n)
    sum <- solanthang[i]
  }
  tilethang <- sum/N
  return(tilethang)
}
a <- play(5,20)
#---------------------------------------Bai 3---------------------------------------------
#a
data03 <- read.csv('giamcan.csv ',header = T)
attach(data03)
names(data03)
nguoi_duoi_65_truoc <- Truoc[Truoc < 65]
nguoi_duoi_65_sau <- Sau[Sau <65]
soLuong <- length(nguoi_duoi_65_sau) + length(nguoi_duoi_65_truoc)
tiLeDuoi65 <- soLuong/(length(Truoc) + length(Sau))
#b
data <- Sau[Sau > 65]
data <- data[data < 75]
tile <- length(data)/(length(Truoc) + length(Sau))
#--------------------------------------Bai 4 ---------------------------------------------
#----------------------------------------Bai 5-------------------------------------------
X <- c(1.3975068, 1.1253621, 0.7472591, 0.8144085, 1.8202663,
       0.8671346, 1.4210106, 1.6784005, 1.3697046, 0.6182268,
       1.9064036, 0.9360782, 1.1175578, 1.2527916, 1.9584229,
       1.3689436, 1.5685716, 1.0691046, 1.6625395, 1.7949509)
X.bar = mean(X)
X.sd = sd(X)
#-----------------------------------Bai 6-----------------------------------------
#a
moPhong <- function(n){
  X <- sample(0:1,n,replace = TRUE)
  return(X)
}
#b
soTien <- function(m){
  a <- rbinom(m,1,0.35)
  tien <- 0
  for(i in 1:m){
    ifelse(a[i] == 1, sum <- sum + 10, sum<- sum - 5)
  }
  return(sum)
}
#--------------------------------------Bai 0.2.2 chuong 2----------------------------------------
chieucao <- seq(130,190)
chieucao.mean <- 156
chieucao.doLech <- 4.6
matDo <- dnorm(chieucao, mean = chieucao.mean, sd = chieucao.doLech)
#b
xacSuat <- pnorm(160, mean = chieucao.mean, sd = chieucao.doLech)
#d
xacsuat <- pnorm(150,mean = chieucao.mean, sd = chieucao.doLech)




