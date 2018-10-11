def make_square(image):
    X=image.crop((0,0,min(image.size),min(image.size)))
    return X
