//video para controlar remotamente sin lag: https://www.youtube.com/watch?v=x-jQn3ZiM4A

	wget https://www.nomachine.com/free/arm/v8/deb -O nomachine.deb
	sudo dpkg -i nomachine.deb
	sudo apt install xfce4
	sudo gedit /usr/NX/etc/node.cfg
	//agregar esta linea en  DefaultDesktopCommand "/usr/bin/startxfce4"
	 DefaultDesktopCommand "/usr/bin/startxfce4" 
	//Guardar y salir
	
//AUMENTO DE MEMORIA RAM: https://www.youtube.com/watch?v=4XYLM_PlXUg
	sudo systemctl disable nvzramconfig
	sudo fallocate -l 4G /mnt/4G.swap
	sudo mkswap /mnt/4G.swap
	sudo swapon /mnt/4G.swap
	cd ..
	cd ..
	cd etc/
	sudo gedit fstab
	//Alli colocan lo siguiente y guardan
	/mnt/4G.swap	none	swap	sw	0	0
	// Si queremos habilitar la memoria zram de nuevo
	sudo systemctl enable nvzramconfig	
	
	
//CONTROL AUTOMATICO DE VENTILADORES:
	sudo apt install python3-dev
	git clone https://github.com/Pyrestone/jetson-fan-ctl

	
// ENTORNO DE SOPORTE JTOP
	sudo apt-get install git cmake
	sudo apt-get install python3-dev
	sudo apt-get install libhdf5-serial-dev hdf5-tools
	sudo apt-get install libatlas-base-dev gfortran
	// INSTALAMOS PIP
	sudo apt install python3-pip
	// JETSON STATS
	sudo -H pip3 install -U jetson-stats