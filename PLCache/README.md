PL Cache Implementation on Gem5
=======

This is a PL-Cache implementation on Gem5.

Reference for PL-Cache model: http://www.cs.cmu.edu/afs/cs/Web/People/lba/LBA_reading_group/papers/Sidechannel_isca07.pdf

	Authors: Ziyun Kong, Xiaoyu Zheng, Cheng Li

	Contacts: {kongzy, xiaoyuzh, elfchris}@umich.edu

-----------------------------
1. Build Gem5:

		$ scons build/X86/gem5.opt


2. Run full-system simulation arm/x86 on ubuntu:

		$ cd 
		$ mkdir full_system_images
		$ cd ~/full_system_images
		$ wget http://www.m5sim.org/dist/current/x86/x86-system.tar.bz2 
		$ wget http://www.m5sim.org/dist/current/m5_system_2.0b3.tar.bz2
		$ tar jvxf x86-system.bar.bz2
		$ tar jvxf m5_system_2.0b3.tar.bz2
		$ echo "export M5_PATH=/home/[username]/full_system_images/" >> ~/.bashrc
		$ source ~/.bashrc
	
		$ cd /PATH_TO_GEM5
		$ ./build/X86/gem5.opt configs/example/fs.py --disk-image=/home/[user_name]/full_system_images/disks/linux-x86.img --kernel=x86_64-vmlinux-2.6.22.9.smp

3. Connect to simulator, open another terminal:

		$ telnet localhost 3456

4. If you want to run a program without using full-system simulation

	1). Install x compiler

		$ sudo apt-get install arm-linux-gnueabi
		
	2). Compile your code

		$ arm-linux-gnueabi-gcc -static -o output source.c

	3). Run program, first line for generating help information
	
		$ build/X86/gem5.opt configs/example/se.py -h 
		$ build/X86/gem5.opt configs/example/se.py -c PATH_TO_BINARY_FILE -i PATH_TO_INPUT_FILE

5. To use the new pseudo instruction call the function declared in util/m5/m5op.h. 
   Then (cross-)compile your source code with the m5 utilities like:

		gcc -o foo foo.c -static -I ${GEM5}/util/m5 ${GEM5}/util/m5/m5op_x86.S


