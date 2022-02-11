sudo yum check-update
curl -fsSL https://get.docker.com/ | sh
sudo systemctl start docker
sudo systemctl status docker
sudo systemctl enable docker

sudo docker pull centos
sudo docker pull ubuntu

#sudo docker image rm --force bitfinex_dock
sudo docker build -t bitfinex_dock .
