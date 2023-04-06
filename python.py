"""You can use this class to represent how classy someone
or something is.
"Classy" is interchangable with "fancy".
If you add fancy-looking items, you will increase
your "classiness".
Create a function in "Classy" that takes a string as
input and adds it to the "items" list.
Another method should calculate the "classiness"
value based on the items.
The following items have classiness points associated
with them:
"tophat" = 2
"bowtie" = 4
"monocle" = 5
Everything else has 0 points.
Use the test cases below to guide you!"""

# class Classy(object):
#     def __init__(self):
#         self.items = [{
#             "tophat": 0,
#             "bowtie": 0,
#             "monocle": 0
#         }]

#     def getClassiness(self):
#         return self.items[0]['tophat'] + self.items[0]['bowtie'] + self.items[0]['monocle']

#     def addItem(self, name):
#         if name == 'tophat':
#             points = 2
#         elif name == 'bowtie':
#             points = 4
#         elif name == 'monocle':
#             points = 5
#         else:
#             points = 0
#         if name in ['tophat', 'bowtie', 'monocle']:
#             self.items[0][name] += points

# me = Classy()

# # Should be 0
# print (me.getClassiness())

# me.addItem("tophat")
# # Should be 2
# print (me.getClassiness())

# me.addItem("bowtie")
# me.addItem("jacket")
# me.addItem("monocle")
# # Should be 11
# print (me.getClassiness())

# me.addItem("bowtie")
# # Should be 15
# print (me.getClassiness())

#####################################################################################################
# Write a function called "show_excitement" where the string
# "I am super excited for this course!" is returned exactly
# 5 times, where each sentence is separated by a single space.
# Return the string with "return".
# You can only have the string once in your code.
# Don't just copy/paste it 5 times into a single variable!


# def show_excitement():
#     # Your code goes here!
#     str = "I am super excited for this course! "
#     return str * 5

# print(show_excitement())

########################################################################################################
# """The LinkedList code from before is provided below.
# Add three functions to the LinkedList.
# "get_position" returns the element at a certain position.
# The "insert" function will add an element to a particular
# spot in the list.
# "delete" will delete the first element with that
# particular value.
# Then, use "Test Run" and "Submit" to run the test cases
# at the bottom."""

# class Element(object):
#     def __init__(self, value):
#         self.value = value
#         self.next = None
        
# class LinkedList(object):
#     def __init__(self, head=None):
#         self.head = head
        
#     def append(self, new_element):
#         current = self.head
#         if current:
#             while current.next:
#                 current = current.next
#             current.next = new_element
#         else:
#             self.head = new_element
            
#     def get_position(self, position):
#         """Get an element from a particular position.
#         Assume the first position is "1".
#         Return "None" if position is not in the list."""
#         current = self.head  # Initialise temp
#         count = 1  # Index of current node
  
#         # Loop while end of linked list is not reached
#         while (current):
#             if (count == position):
#                 return current
#             count += 1
#             current = current.next
#         return None
    
#     def insert(self, new_element, position):
#         """Insert a new node at the given position.
#         Assume the first position is "1".
#         Inserting at position 3 means between
#         the 2nd and 3rd elements."""
#         count=1
#         current = self.head
#         if position == 1:
#             new_element.next = self.head
#             self.head = new_element
#         while current:
#             if count+1 == position:
#                 new_element.next =current.next      # 1 --> 2 --> 3
                                                             #⬇
                #current.next = new_node                     #4 --> 3
#                 current.next = new_element
#                 return
#             else:
#                 count+=1
#                 current = current.next
    
    
#     def delete(self, value):
#         """Delete the first node with a given value."""
#         current = self.head
#         if current.value == value:
#             self.head = current.next
#         #Delete the node with a given value:
#         else:
#             while current:
#                 if current.value == value:
#                     break
#                 prev = current
#                 current = current.next
#             if current == None:
#                 return 'Node/Element not found'
#             prev.next = current.next
#             current = None

# # Test cases
# # Set up some Elements
# e1 = Element(1)
# e2 = Element(2)
# e3 = Element(3)
# e4 = Element(4)

# # Start setting up a LinkedList
# ll = LinkedList(e1)
# ll.append(e2)
# ll.append(e3)

# # print(ll.head.value)
# # print(ll.head.next)

# # Test get_position
# # Should print 3
# print(ll.head.next.next.value)
# # Should also print 3
# print(ll.get_position(3).value)

# # # Test insert
# ll.insert(e4,3)
# # # Should print 4 now
# print (ll.get_position(3).value)

# # # Test delete
# ll.delete(1)
# # # Should print 2 now
# print (ll.get_position(1).value)
# # # Should print 4 now
# print (ll.get_position(2).value)
# # # Should print 3 now
# print (ll.get_position(3).value)

###########################################################################################

class Element(object):
    def __init__(self, value):
        self.value = value
        self.next = None
        
class LinkedList(object):
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, new_element):
        newNode = Element(new_element)
        if self.head:
            self.tail.next = newNode
            self.tail = newNode
        else:
            self.head = newNode
            self.tail = self.head

    def get_position(self, position):
        """Get an element from a particular position.
        Assume the first position is "1".
        Return "None" if position is not in the list."""
        current = self.head  # Initialise temp
        count = 1  # Index of current node
  
        # Loop while end of linked list is not reached
        while (current):
            if (count == position):
                return current
            count += 1
            current = current.next
        return None

# Test cases
# Set up some Elements


# Start setting up a LinkedList
ll = LinkedList()
ll.append(1)
ll.append(2)
ll.append(3)

# print(ll.head.value)
# print(ll.head.next)

# Test get_position
# Should print 3
print(ll.head.next.next.value)
# Should also print 3
print(ll.get_position(3).value)