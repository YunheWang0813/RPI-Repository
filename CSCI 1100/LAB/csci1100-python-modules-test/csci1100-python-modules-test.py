import nose
from PIL import Image
import cStringIO
import urllib2 as urllib
import Tkinter as tk

def test_nose():
	assert True == True
	print "Tested Nose: Assertion Passed"

def test_PIL():
	img_file = urllib.urlopen("http://www.ecse.rpi.edu/~agung/logo.jpg")
        im = cStringIO.StringIO(img_file.read())
	resized_image = Image.open(im)
	cropped_image = resized_image.crop((0,0,resized_image.size[1],resized_image.size[1]))
	cropped_image.rotate(90).show()
	print "Testing PIL: RPI logo rotated 90 degrees is shown."

test_nose()
test_PIL()

