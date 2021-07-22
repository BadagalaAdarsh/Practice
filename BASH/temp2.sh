for file in *.jpg
do
	mv $file IMG_${file:3:8}_${file:11:50}
done
