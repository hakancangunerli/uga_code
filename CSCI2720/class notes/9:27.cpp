// last class:

/*
stack, stack adt operations 

you're not doing search while push and pop (because you get it from the top of the stack or the bottom of the stack)

top points to the top of the stack

when you push, you can call the isFull method to see if it's full yet, if it's you can just call an exception 
when you pop , you can call the isEmpty method to see if it's empty yet, if it's you can just call an exception

all constant type 
if ( isEmpty()){
    throw "Stack is empty";
}else{
    return--; 
}

ItemType top(){
    if ( isEmpty()){
        throw "Stack is empty";
    }else{
        return info[top];
}

slide 40, there'll be a pointer but it's still an array-based implementation 

Queue: 
dequeue: remove the first item in the queue
eqnqueue : add the item to the rear of the queue

*/