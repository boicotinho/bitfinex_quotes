#sudo docker run -it --mount type=bind,source=/home/fabio/docker_projects/home_mnt,target=/root/share/ bitfinex_dock -cap-add=SYS_PTRACE --security-opt seccomp=unconfined market_py2cpp
#sudo docker run -it bitfinex_dock
# Allow gdb to attach with ASLR (address space layout randomization - security feature)
sudo docker run -it --cap-add=SYS_PTRACE --security-opt seccomp=unconfined  bitfinex_dock
