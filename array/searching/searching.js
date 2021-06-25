const binarySearch = (arr, k ) =>{
    let low = 0
    let high = arr.length -1

    while(low <=high){
        let mid = (low+high)/2
        if(arr[mid] == k){
            return mid;
        }else{
            if(arr[mid] > k){
                high = mid -1
            }else{
                low = low+1
            }
        }
    }
    return -1
}



const arr1 = [4, 3, 5, 6, 4, 3, 5, 6, 9, 10]

console.log(arr1.indexOf(6)) // returns the index of key
console.log(arr1.find(ele => ele == 6)) // returns the first no. matching the condition

console.log(binarySearch([1,2,3,4,5,6], 5))
