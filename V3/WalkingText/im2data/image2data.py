# import OpenCV
import numpy
import cv2

NumOfRows = 60
# read the image
img = cv2.imread('wall.jpg')

print(len(img))
# imgG = cv2.cvtColor(img,  cv2.COLOR_BGR2GRAY);
# print(img[0])
print(len(img[0]))


theFile = open("./LED/ImgConst.h", "w")

theFile.writelines( "#define lengthOfImg    "+str(len(img[0])))
theFile.writelines( "\n \n" )


theFile.writelines( "const PROGMEM byte img["+str(NumOfRows)+"]["+str(len(img[0]))+"][3] = {")
theFile.writelines( "\n" )


# theFile.writelines( "weqqeq" )
scaleLuminance=8; #1/6

for row in range(NumOfRows):
	theFile.writelines( "{" )
	for col in range(len(img[row])):
		# print(col)
		theFile.writelines( "{" )
		for rgb in range(2):
			# print(img[row][col][rgb])
			theFile.writelines(str(int(img[row][col][rgb]/scaleLuminance))+",")	
		theFile.writelines(str(int(img[row][col][2]/scaleLuminance)))	

		if col!=len(img[row])-1:
			theFile.writelines("},")
		else:
			theFile.writelines("}")

	if row!=NumOfRows-1:
		theFile.writelines("},\n")	
	else:
		theFile.writelines("}\n")	

		

theFile.writelines( "};\n" )

theFile.close()
# show the image
cv2.imshow('image',img)


# close and exit
cv2.waitKey(0)
cv2.destroyAllWindows()