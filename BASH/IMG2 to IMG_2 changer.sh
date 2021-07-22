for file in *.jpg
do
        if [[ $file = IMG2* ]]
        then
                first=${file:3:8}
                second=${file:11:6}
                mv $file IMG_$first_$second.jpg
                echo "file renamed"
        fi
done

