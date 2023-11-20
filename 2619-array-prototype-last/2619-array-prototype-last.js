Array.prototype.last = function() {
    // Check if the element is zero then return -1;
    if(this.length == 0){
        return -1;
    }else{ //Else there are 1 or more elements then simply return element with index array length - 1
        return this[this.length-1];
    }
};