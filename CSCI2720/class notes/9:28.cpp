/* item = info[front];
front and rear are data memembers, and indices 

item = queue.Dequeue();
Itemtype dequeue(){
    item = info[front];
    front = front+1; 
    return item;
}
void enqueue(Itemtype item){
    info[rear] = item;
     rear = rear +1; 
    }
if you use this logic, your queue will be full even if you delete elements. if you want to make an addition, we'd make our queue circular 


instead here's how enqueue should look like:

enqueue{
    rear = (real+1 ) % size;
    info[rear] = item;
}
it made it circular 

dequeue{
    item = info[front];
    front = (front+1) % size;
    return item;
}


how do you make queue equal empty, just make rear front
keep front empty 


then you'd have to make the constructor queue 
maxQue = maxQue +1; 
items = new Itemtype[maxQue];
front =  maxQue -1; 
rear = maxQue -1; 


*/ 