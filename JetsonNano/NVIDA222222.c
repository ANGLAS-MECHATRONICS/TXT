- copia la carpeta "NVIDIA-Jetson-IMX708-RPICAM3_deb" en Descargas
usuario: anglas 
ipwlan: 192.168.158.107

	ssh anglas@192.168.158.107
	sudo chmod o+w /home/nvidia/	
	scp /home/anglas/Descargas/NVIDIA-Jetson-IMX708-RPICAM3_deb/debian_nano/nano.deb anglas@192.168.158.107:/home/nvidia/
	sudo dpkg -i --force-overwrite /home/anglas/Descargas/NVIDIA-Jetson-IMX708-RPICAM3_deb/debian_nano/nano.deb
	//esto es para ver el contenido nada mas
	sudo cat /boot/extlinux/extlinux.conf 
	sudo apt-get install nano
	sudo nano /boot/extlinux/extlinux.conf
	sudo reboot
	
	//revisar proc/config.tz  (ctrl+f buscar imx708)
	//probar la camara
	
	export SENSOR_ID=1
	FRAMERATE=14 
	gst-launch-1.0 nvarguscamerasrc sensor-id=$SENSOR_ID ! "video/x-raw(memory:NVMM),width=4608,height=2592,framerate=$FRAMERATE/1" ! queue ! nvegltransform ! nveglglessink
	
	//4608 x 2592 @ 14fps (solo permite esta resolucion)
	gst-launch-1.0 nvarguscamerasrc sensor-id=0 ! "video/x-raw(memory:NVMM),width=4608,height=2592,framerate=14/1" ! queue ! nvegltransform ! nveglglessink
	
	
	pip3 install nanocamera
	sudo apt-get install python-pip
	pip install nanocamera
	

		
	//Comando para inicial sin interfaz grafica, solo pantalla negra y comandos
	sudo systemctl set-default multi-user.target
	//Comando para revertir eso
	sudo systemctl set-default graphical.target
	


	
	



	



	
	

sudo apt update
sudo apt install git 
sudo apt install git wget 
sudo apt install git quilt 
sudo apt install git build-essential 
sudo apt install git bc 
sudo apt install git libncurses5-dev libncursesw5-dev 
sudo apt install git rsync

cd
wget https://developer.nvidia.com/embedded/l4t/r32_release_v7.2/sources/t210/public_sources.tbz2 -O public_sources.tbz2
tar -xjf public_sources.tbz2 Linux_for_Tegra/source/public/kernel_src.tbz2 --strip-components 3
