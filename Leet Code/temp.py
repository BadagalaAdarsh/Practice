def sortBoxes(boxList):
    old_boxes = []
    new_boxes = []

    for box in boxList:
        pos = box.index(' ')
        char = box[pos+1]

        if char.isdigit():
            new_boxes.append(box)
        else:
            old_boxes.append(box)

    old_boxes.sort()

    return old_boxes + new_boxes