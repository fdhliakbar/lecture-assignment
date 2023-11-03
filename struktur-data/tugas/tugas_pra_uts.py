# Nomor 1 Nilai acak rentang 1 - 10 dengan N  = 5
# values = [5, 1, 3, 8, 4]

# Nomor 3 (Array of randomValues)

def randomValues(values, arrSize):
    tempValues = [0] * (arrSize - 1)

# Nomor 3

def delArray(values, arrSize, position):
    tempValues = [0] * (arrSize - 1)
    
    for i in range(position, arrSize - 1):
        values[i] = values[i + 1]

    for i in range(arrSize - 1):
        tempValues[i] = values[i] 
    
    return tempValues

values = [5, 1, 3, 8, 4]
arrSize = 5
position = 3

valuesAfterDel = delArray(values, arrSize, position)
print("Output Menghapus Elemen Index ke", position, ":", valuesAfterDel, '\n')


# Nomor 4 (Linked List)

def createNode(data):
    return {'data': data, 'next': None}

def insertAtTail(linkedList, data):
    newNode = createNode(data)
    
    if linkedList is None:
        return newNode
    
    current = linkedList

    while current['next'] is not None:
        current = current['next']
    
    current['next'] = newNode

    return linkedList

def printLinkedList(linkedList):
    while linkedList:
        print(linkedList ['data'], end=" -> ")
        linkedList = linkedList ['next']
    print("None")

def totalValues(linkedList):
    if linkedList is None:
        return 0
    
    current = linkedList
    total = 0
    
    while current is not None:
        total += current['data']
        current = current['next']
    
    return total

linkedList = createNode(320)
linkedList = insertAtTail(linkedList, 80)
linkedList = insertAtTail(linkedList, 60)
linkedList = insertAtTail(linkedList, 60)
total = totalValues(linkedList)
printLinkedList(linkedList)
print("Output total nilai : ", total, "\n")

# Nomor 5 (Circular Linked List)

def insertAtHead(linkedList, data):
    newData = createNode(data)

    if not circularLinkedList:
        newData['next'] = newData
        return newData
    else:
        tempCircularLinkedList = circularLinkedList

        while tempCircularLinkedList['next'] != circularLinkedList:
            tempCircularLinkedList = tempCircularLinkedList['next']
        
        tempCircularLinkedList['next'] = newData
        newData['next'] = circularLinkedList

        return circularLinkedList

def printCircularLinkedList(circularLinkedList):
    if not circularLinkedList:
        print("Circular Linked List is empty.")
        return
    
    tempCircularLinkedList = circularLinkedList
    while True:
        print(tempCircularLinkedList['data'], end=" -> ")
        tempCircularLinkedList = tempCircularLinkedList['next']
        if tempCircularLinkedList == circularLinkedList:
            break
    print("None")

circularLinkedList = None
circularLinkedList = (insertAtHead(circularLinkedList, '5'))
circularLinkedList = (insertAtHead(circularLinkedList, '8'))
circularLinkedList = (insertAtHead(circularLinkedList, '4'))
circularLinkedList = (insertAtHead(circularLinkedList, '2'))
circularLinkedList = (insertAtHead(circularLinkedList, '6'))
printCircularLinkedList(circularLinkedList)

# Nomor 6 (Delete Node After at Head)
def delAtHead(linkedList, data):
    genap = 1