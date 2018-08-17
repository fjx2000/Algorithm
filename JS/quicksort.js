let arrayToBeSorted = [3,2,6,8,5,4,9,7,1]
//let arrayToBeSorted = [1]
function partition(leftPos, rightPos) {
	if(rightPos > leftPos){
  	let pivot = arrayToBeSorted[leftPos]
    let i = leftPos
    let j = rightPos
    while(i <= j){
      do{
         i++
      }while(i < rightPos && arrayToBeSorted[i] < pivot)
      while(j > 0 && arrayToBeSorted[j] > pivot){
       j--
      }
      if(i < j){
        let tmp = arrayToBeSorted[i]
        arrayToBeSorted[i] = arrayToBeSorted[j]
        arrayToBeSorted[j] = tmp      
      }
    }
    
    arrayToBeSorted[leftPos] = arrayToBeSorted[j]
    arrayToBeSorted[j] = pivot
    console.log("return middle position", j)
    return j
    
  }
  else
  {
    console.log("leftPos equals rightPos", leftPos, rightPos)
  }
}

function qsort(leftPos, rightPos){
	if(leftPos < rightPos){
    let pivotPos= partition(leftPos, rightPos)
    qsort(leftPos, pivotPos-1)
    qsort(pivotPos+1, rightPos)
  }
}

qsort(0, arrayToBeSorted.length - 1 )
console.log(arrayToBeSorted)
