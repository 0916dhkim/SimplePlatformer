# List of all resource files
set (resource_files
	font/Lato/Lato-Regular.ttf
	font/Lato/OFL.txt
)

# Configure each file to be copied into build directory
foreach (file ${resource_files})
	configure_file (${file} ${file} COPYONLY)
endforeach (file)
