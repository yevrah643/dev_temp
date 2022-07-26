# vim-cmake-boilerplate

The companion repository for the [**Vim: Setting up a Build System and Code Completion for C and C++**](https://dane-bulat.medium.com/vim-setting-up-a-build-system-and-code-completion-for-c-and-c-eb263c0a19a1) guide.

#Some Notice for using the LSP and CMAKE together: 
##Problem 1: Improperly detect headers/libraries though been listed on CMAKE 
Ans: [ONLY headers file -> [INTERFACE]]
	1. Create the target libraries in CMakeLists.txt
	add_library(name [properties])
	target_include_directories(name [properties] dir/)

	2. Link the libraries target to the exe target!
	target_link_libraries(exe_name PUBLIC library_name)

Ans: [SOURCE & HEADER files -> [No PROPERTIES]!!!!]
	1. Create the target: 
	add_library(name [property] source_files_path)
	target_include_directories(name [INTERFACE] [dir/])

##Problem 2: header/source files can't use LSP
Ans: 	
	1. Must be contained: 
		compile_commands.json [CMAKE]
		.ccls
			*Editable file, including the library's directories/paths in the .ccls
			*Regular problems with the headers! 	
	2. Check through the Problem 1 for all necessary libraries are included! 
	
Ans: 
	1. MacOS: if install ccls via HomeBrew, it will also install a separate clang/llvm package 
		The llvm directory is like /usr/local/Cellar/llvm/14.0.6_1

		.ccls file on root project directory should be: 
			clang
			-ccc-install-dir
			/usr/local/Cellar/llvm/14.0.6_1/bin
			%cpp -std=c++11
			%cpp -stdlib=libc++	

		It uses clang installed via homebrew. The standard C++ header file location now becomes /usr/local/Cellar/llvm/11.0.0/include/c++/v1/
