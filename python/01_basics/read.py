import cv2 as cv

img = cv.imread('C:/Users/sneha/OneDrive/Pictures/Saved Pictures/family_large.jpg')

if img is None:
    print("Image not found or path is incorrect.")
else:
    cv.imshow('Original', img)
    cv.waitKey(0)
    cv.destroyAllWindows()
