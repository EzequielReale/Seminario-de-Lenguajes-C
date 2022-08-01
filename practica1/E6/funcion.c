char ASCII(int x){
    if ((x >= 0) & (x < 255))  {
        return (char) x;
    }
    else{
        return (char) 0;
    }
}