
let arrayToBeSorted = [12,3,2,11,6,8,15,5,13,10,4,9,7,14,1,0]
//let arrayToBeSorted = [2,1,4,3]

function merge(leftArray, rightArray){
	let mergedArray = []
  let i = 0, j = 0, k = 0
  while(i < leftArray.length && j < rightArray.length){
    if(leftArray[i] <= rightArray[j]){
  	mergedArray[k++] = leftArray[i++]
    }
    else{
      mergedArray[k++] = rightArray[j++]
    }
  }
  while(i < leftArray.length){
  	mergedArray[k++] = leftArray[i++]
  }
  while(j < rightArray.length){
  	mergedArray[k++] = rightArray[j++]
  }
  console.log("Merged Array: ", mergedArray)
  return mergedArray
}

function mergeSort(leftPos, rightPos){
  //console.log(leftPos, rightPos)
  if(leftPos == rightPos){
    let newArray = [arrayToBeSorted[leftPos]]
  	return newArray
  }
	let midPos = Math.floor((leftPos + rightPos)/2)
  return merge(mergeSort(leftPos, midPos), mergeSort(midPos+1, rightPos))
}

console.log ("Sorted Array: ", mergeSort(0, arrayToBeSorted.length-1))
