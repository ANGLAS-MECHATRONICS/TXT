//Instalar ubuntu desde microsoft store
//si adesea desintalar ubuntu (esto es en powershell administrador)
	wsl --unregister Ubuntu-18.04
	wsl.exe --update
//Verificamos en que version de WSL estamos 1 o 2 (esto es en powershell administrador)
	wsl --list --verbose 
	wsl.exe --list --verbose 
//Cambiar a WSL a version 2 (esto es en powershell administrador)
	wsl --set-version Ubuntu-18.04 2
//En Ubuntu actualizar
	sudo apt update
	sudo apt upgrade
	
	sudo apt install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils
	sudo apt install binfmt-support
	
//Verificar que este el archivo "qemu-aarch64"
	ls /proc/sys/fs/binfmt_misc/
//Si no esta, ejecutar el siguiente comando

	wget https://github.com/qemu/qemu/raw/master/scripts/qemu-binfmt-conf.sh
	chmod +x qemu-binfmt-conf.sh
	sudo ./qemu-binfmt-conf.sh --qemu-path /usr/bin --qemu-suffix -static --debian
	sudo update-binfmts --import qemu-aarch64
//Descargar "sdkmanager_1.9.3-10904_amd64.deb" y copiar el archivo en /home/anglas
	sudo apt install ./sdkmanager_1.9.3-10904_amd64.deb
	sudo apt install ./sdkmanager_2.0.0-11405_amd64.deb

//cualquiera de los dos
	sdkmanager --query non-interactive --login-type devzone //sdkmanager_2.0.0-11405_amd64.deb
	sdkmanager --query noninteractive --logintype devzone   //sdkmanager_1.9.3-10904_amd64.deb
	
//seleccionar el jetpack a instalar en mi caso 4.6.4 para jetson nano
	sdkmanager --cli --action install --login-type devzone --product Jetson --version 4.6.4 --target-os Linux --host --target JETSON_NANO_TARGETS --flash --additional-sdk 'DeepStream 6.0.1'
	sdkmanager --cli --action install --login-type devzone --product Jetson --version 4.6.2 --target-os Linux --host --target JETSON_NANO_TARGETS --flash
//copiar el link (el QR no),pegarlo en un navegador e iniciar sesion
//luego automaticamente continuara y esperar que descargue todo  e instale

- Descargar e instalar usbipd-win 4.1.0.msi
- Colocar la SD en un adaptador y conectar al PC por USB
- Abrir powershell en administrador y verificar si esta el USB	
	usbipd list
- Buscar el dispositivo USB: (2-4    05e3:0745  Dispositivo de almacenamiento USB                             Not shared)
- Luego ejecutar este comando para a Shared: (2-4    05e3:0745  Dispositivo de almacenamiento USB                             Shared)
	usbipd bind --busid 2-4 
-Ahora conectar a Ubuntu el USB
	usbipd attach --wsl --busid 2-4
	usbipd detach --busid 2-4 //para desconectar
- Verificar con este comando y debe aparecer el dispositivo con Attached
	usbipd list
- Ahora abrir otra terminal de Ubuntu-18.04 y verificar que este el dispositivo: (Bus 001 Device 002: ID 05e3:0745 Genesys Logic, Inc. Logilink CR0012)
	lsusb
- Ahora antes de empezar hay que actualizar y ejecutar todos los siguientes comandos en Ubuntu-18.04
	sudo apt update
	sudo apt install iputils-ping iproute2 netcat iptables dnsutils network-manager usbutils net-tools python3-yaml dosfstools libgetopt-complete-perl openssh-client binutils xxd cpio udev dmidecode -y
	sudo apt install linux-tools-virtual hwdata
	//Ejecutar dos veces el mismo comando 
	sudo update-alternatives --install /usr/local/bin/usbip usbip `ls /usr/lib/linux-tools/*/usbip | tail -n1` 20 
	*/
- Ahora si colocar 
	lsusb
	

	
	
	
	



		
	








2-4    05e3:0745  Dispositivo de almacenamiento USB                             Not shared
