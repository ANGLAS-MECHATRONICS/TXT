//INSTALL OPENCV 4.5.1: https://www.youtube.com/watch?v=P-EZr0zy53g
	List of commands:

	sudo apt-get install python3-pip 
	pip3 install virtualenv 
	python3 -m virtualenv -p python3 env --system-site-packages    
	source env/bin/activate 
	python -c 'import cv2; print(cv2.__version__)' 

	Create SwapFile:
	sudo fallocate -l 4G /var/swapfile 
	sudo chmod 600 /var/swapfile
	sudo mkswap /var/swapfile
	sudo swapon /var/swapfile
	sudo bash -c 'echo "/var/swapfile swap swap defaults 0 0" >> /etc/fstab'


	Reboot your PC: sudo reboot
	After rebooting check swap space  by using this command:   free -h

	Install these Dependencies before installing OpenCV:
	//TODO ESTO INSTALAR DENTRO DEL ENTORNO VIRTUAL: source env/bin/activate 

	sudo sh -c "echo '/usr/local/cuda/lib64' >> /etc/ld.so.conf.d/nvidia-tegra.conf"
	sudo ldconfig
	sudo apt-get install build-essential cmake git unzip pkg-config
	sudo apt-get install libjpeg-dev libpng-dev libtiff-dev
	sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev
	sudo apt-get install libgtk2.0-dev libcanberra-gtk*
	sudo apt-get install python3-dev python3-numpy python3-pip
	sudo apt-get install libxvidcore-dev libx264-dev libgtk-3-dev
	sudo apt-get install libtbb2 libtbb-dev libdc1394-22-dev
	sudo apt-get install libv4l-dev v4l-utils
	sudo apt-get install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev
	sudo apt-get install libavresample-dev libvorbis-dev libxine2-dev
	sudo apt-get install libfaac-dev libmp3lame-dev libtheora-dev
	sudo apt-get install libopencore-amrnb-dev libopencore-amrwb-dev
	sudo apt-get install libopenblas-dev libatlas-base-dev libblas-dev
	sudo apt-get install liblapack-dev libeigen3-dev gfortran
	sudo apt-get install libhdf5-dev protobuf-compiler
	sudo apt-get install libprotobuf-dev libgoogle-glog-dev libgflags-dev

	Download OpenCV:
	cd ~
	wget -O opencv.zip https://github.com/opencv/opencv/archive/4.5.1.zip 
	wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.5.1.zip 
	unzip opencv.zip 
	unzip opencv_contrib.zip

	Now rename the directories. Type each command below, one after the other.
	mv opencv-4.5.1 opencv
	mv opencv_contrib-4.5.1 opencv_contrib
	rm opencv.zip
	rm opencv_contrib.zip

	Lets build OpenCV now:
	cd ~/opencv
	mkdir build
	cd build 


	//copy and paste this entire block of commands below into your terminal.
	cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr -D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib/modules -D EIGEN_INCLUDE_PATH=/usr/include/eigen3 -D WITH_OPENCL=OFF -D WITH_CUDA=ON -D CUDA_ARCH_BIN=5.3 -D CUDA_ARCH_PTX="" -D WITH_CUDNN=ON -D WITH_CUBLAS=ON -D ENABLE_FAST_MATH=ON -D CUDA_FAST_MATH=ON -D OPENCV_DNN_CUDA=ON -D ENABLE_NEON=ON -D WITH_QT=OFF -D WITH_OPENMP=ON -D WITH_OPENGL=ON -D BUILD_TIFF=ON -D WITH_FFMPEG=ON -D WITH_GSTREAMER=ON -D WITH_TBB=ON -D BUILD_TBB=ON -D BUILD_TESTS=OFF -D WITH_EIGEN=ON -D WITH_V4L=ON -D WITH_LIBV4L=ON -D OPENCV_ENABLE_NONFREE=ON -D INSTALL_C_EXAMPLES=OFF -D INSTALL_PYTHON_EXAMPLES=OFF -D BUILD_NEW_PYTHON_SUPPORT=ON -D BUILD_opencv_python3=TRUE -D OPENCV_GENERATE_PKGCONFIG=ON -D BUILD_EXAMPLES=OFF ..
	
	//Build OpenCV. This command below will take a long time (around 2 hours), 
	make -j4     

	//Finish the install:
	cd ~
	sudo rm -r /usr/include/opencv4/opencv2
	cd ~/opencv/build
	sudo make install
	sudo ldconfig
	make clean
	sudo apt-get update 

	Verify OpenCV Installation
	#open python3 shell
	python3
	import cv2
	cv2.__version__
	
	python3 -c "import cv2; print(cv2.__version__)"


//INSTAL JTOP
	Install jtop, a system monitoring software for Jetson Nano.
	cd ~
	sudo -H pip3 install -U jetson-stats 
	sudo reboot
	jtop

//TEST CAMERA 
	Test Your Camera on Jetson Nano:
	Turn on your Jetson Nano.
	Open a new terminal window, and type:
	ls /dev/video0   #csi camera
	ls /dev/video*   # show you a list of cameras

	Take a Photo:
	nvgstcapture-1.0 --orientation=2 --prev-res=3      # for testing CSI camera
	# V4L2 USB camera 
	nvgstcapture-1.0 --camsrc=0 --cap-dev-node=1

------------------------------------------------------------------------------------------------------------------------------------------
SOLUCION MOMENTANEA

sudo usermod -aG gpio $USER
sudo chown root.gpio /dev/gpiochip0
sudo chmod 660 /dev/gpiochip0

sudo usermod -aG gpio $USER
sudo chown root.gpio /dev/gpiochip1
sudo chmod 660 /dev/gpiochip1
-----------------------------------------------------------------------------------------------------------------------------------------------

SOLUCION DEFINITIVA - https://github.com/NVIDIA/jetson-gpio/issues/20

sudo nano /etc/udev/rules.d/99-gpio.rules

-Agregar estas lineas de codigo al archivo: 99-gpio.rules

SUBSYSTEM=="gpio*", PROGRAM="/bin/sh -c '\
    chown -R root:gpio /sys/class/gpio && chmod -R 770 /sys/class/gpio;\
    chown -R root:gpio /dev/gpiochip0 && chmod -R 660 /dev/gpiochip0\
'"

SUBSYSTEM=="gpio*", PROGRAM="/bin/sh -c '\
    chown -R root:gpio /sys/class/gpio && chmod -R 770 /sys/class/gpio;\
    chown -R root:gpio /dev/gpiochip1 && chmod -R 660 /dev/gpiochip1\
'"

sudo usermod -aG gpio $USER
sudo udevadm control --reload-rules

Luego reiniciar y listo
-----------------------------------------------------------------------------------------------------------------------------------------------------
//INSTALAR VISUAL STUDIO CODE ON JETSON NANO
	sudo apt install python3-pip	
	pip3 install --upgrade setuptools
	//Descargar visual studio code desde ese link
	https://update.code.visualstudio.com/1.83.1/linux-deb-arm64/stable
	//Una vez descargado, abrir la carpeta de descargas y ahi abrir una terminal
	sudo dpkg -i code_1.83.1-1696982739_arm64.deb
	
	//Abrimos visual studio code y en extensiones instalamos python
	//Luego en este video esta como activar el entorno virtual: https://www.youtube.com/watch?v=6xwHqCYvaRc&t=1s
_______________________________________________________
//INSTALAR NANOCAMERA
	sudo apt update
	sudo apt install python3 python3-pip
	pip3 install nanocamera
//instalar tensorflow: todo dentro del entorno virtual: source env/bin/activate
	sudo apt-get update
	sudo apt-get install libhdf5-serial-dev hdf5-tools libhdf5-dev zlib1g-dev zip libjpeg8-dev liblapack-dev libblas-dev gfortran
	sudo apt-get install python3-pip
	sudo python3 -m pip install --upgrade pip
	//////////////////////////////////
	sudo apt-get update
	sudo apt-get install libhdf5-serial-dev hdf5-tools libhdf5-dev zlib1g-dev zip libjpeg8-dev liblapack-dev libblas-dev gfortran
	sudo apt-get install python3-pip
	sudo pip3 install -U pip testresources setuptools
	sudo ln -s /usr/include/locale.h /usr/include/xlocale.h
	pip3 install Cython==0.29.36
	pip3 install pkgconfig
	git clone https://github.com/h5py/h5py.git
	//entrar en la carpeta
	//git checkout 3.1.0
	//git cherry-pick 3bf862daa4ebeb2eeaf3a0491e05f5415c1818e4
	H5PY_SETUP_REQUIRES=0 pip3 install . --no-deps --no-build-isolation
	
	//sudo pip3 install -U numpy==1.19.4 future mock keras_preprocessing keras_applications gast==0.2.1 protobuf pybind11 packaging
	//sudo pip3 install --extra-index-url https://developer.download.nvidia.com/compute/redist/jp/v461 tensorflow
	///////////////////////////////
	
	sudo pip3 install -U setuptools
	sudo pip3 install -U testresources setuptools
	sudo pip3 install -U testresources setuptools==65.5.0
	sudo pip3 install -U numpy==1.22 future==0.18.2 mock==3.0.5 keras_preprocessing==1.1.2 keras_applications==1.0.8 gast==0.4.0 protobuf pybind11 cython pkgconfig packaging h5py==3.7.0
	
	
	
	
//INSTALAR MEDIAPIPE
	https://www.youtube.com/watch?v=RAfkrusLnkM&t=131s 
	https://github.com/Melvinsajith/How-to-Install-Mediapipe-in-Jetson-Nano
	
	sudo apt update
	sudo apt-get update
	sudo apt-get install libhdf5-serial-dev hdf5-tools libhdf5-dev zlib1g-dev zip libjpeg8-dev liblapack-dev libblas-dev gfortran
	sudo apt-get install python3-pip
	sudo pip3 install -U pip testresources setuptools==49.6.0
	sudo pip3 install -U --no-deps numpy==1.19.4 future==0.18.2 mock==3.0.5 keras_preprocessing==1.1.2 keras_applications==1.0.8 gast==0.4.0 protobuf pybind11 cython pkgconfig
	sudo env H5PY_SETUP_REQUIRES=0 pip3 install -U h5py==3.1.0
	
	//python -c 'import cv2; print(cv2.__version__)' 
	
	sudo apt-get install python3-opencv 
	sudo apt-get remove python3-opencv 
	
	git clone https://github.com/google/mediapipe.git
	cd mediapipe
	sudo apt-get install -y libopencv-core-dev  libopencv-highgui-dev libopencv-calib3d-dev libopencv-features2d-dev libopencv-imgproc-dev libopencv-video-dev
	sudo chmod 744 setup_opencv.sh
	./setup_opencv.sh
	
	//sudo pip3 install opencv_contrib_python
	sudo pip3 install -v opencv_contrib_python

	sudo apt install curl
	
	//descargar este archivo: https://drive.google.com/file/d/1lHr9Krznst1ugLF_ElWGCNi_Y4AmEexx/view?usp=sharing
	//ubicarse en su carpeta y abrir una terminal
	unzip mediapipe-bin.zip
	cd mediapipe-bin  
    //sudo pip3 install numpy-1.19.4-cp36-none-manylinux2014_aarch64.whl mediapipe-0.8.5_cuda102-cp36-none-linux_aarch64.whl
	sudo pip3 install -v numpy-1.19.4-cp36-none-manylinux2014_aarch64.whl mediapipe-0.8.5_cuda102-cp36-none-linux_aarch64.whl
    pip3 install dataclasses
	
	
//INSTALAR SERVOKIT (NO me funciono para servos ) 
	git clone https://github.com/JetsonHacksNano/ServoKit
	cd Servokit
	ls -l /dev/i2c*
	//verificamos aqui, y veremos que no hay "i2c"
	groups
	//tengo conectando el PCA9685 en I2C1 de jetson nano, y verificamos que salga la direccion 40
	sudo i2cdetect -y -r 1
	./installServoKit.sh
	sudo reboot
	//verificamos otra vez y esta vez si veremos agregado "i2c"
		
//INSTALAR PCA9685 - I2C PARA SERVOS: https://www.youtube.com/watch?v=D2gSvXo0qT8
	//crear una carpeta de librerias, ingresar a la carpeta y abrir una terminal
	mkdir PCA9685
	sudo apt-get install python-smbus
	sudo apt-get install i2c-tools
	sudo pip install adafruit-pca9685
	//verificamos aqui, y veremos que no hay "i2c"
	groups
	//tengo conectando el PCA9685 en I2C1 de jetson nano, y verificamos que salga la direccion 40
	sudo i2cdetect -y -r 1
	//agregamos i2c
	sudo usermod -a -G i2c anglas
	//verificamos otra vez y esta vez si veremos agregado "i2c"
	groups
	sudo reboot
	


	
	


		



