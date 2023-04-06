////////////////////////FREQUENCY COUNTER
//Solution 1:

//Write a function called same, which accepts two arrays. The function should return true if every value in the array
// has its corresponding value squared in the second array. The frequency of values must be the same.

// const same = (arr1, arr2) => {
//   if (arr1.length !== arr2.length) return false

//   const lookUp = {}

//   for (const num of arr2) {
//     lookUp[num] ? lookUp[num]++ : (lookUp[num] = 1)
//   }

//   for (const num of arr1) {
//     if (!lookUp[num ** 2]) return false
//     else lookUp[num ** 2] -= 1
//   }

//   return true
// }

//Solution 2:
// const same = (arr1, arr2) => {
//   if (arr1.length !== arr2.length) return false

//   const counter1 = {}
//   const counter2 = {}

//   for (const num of arr1) {
//     counter1[num] ? counter1[num]++ : (counter1[num] = 1)
//   }

//   for (const num of arr2) {
//     counter2[num] ? counter2[num]++ : (counter2[num] = 1)
//   }

//   for (const key in counter1) {
//     if (counter2[key ** 2] !== counter1[key]) return false
//   }

//   return true
// }

// console.log(same([1, 2, 3], [4, 1, 9]))
// console.log(same([1, 2, 3], [1, 9]))
// console.log(same([1, 2, 1], [4, 4, 1]))
// console.log(same([1, 2, 3, 2, 5], [9, 1, 4, 4, 11]))

///////////////////////////////////////Frequency Counter - validAnagram///////////////////////////////////////////////////

// Given two strings, write a function to determine if the second string is an anagram of the first. An anagram is a word, phrase, or name formed by rearranging the letters of another, such as cinema, formed from iceman.

// Your solution MUST have the following complexities:

// Time: O(N)

//Solution 1:
// const validAnagram = (str1, str2) => {
//   return str1.split('').sort().join('') === str2.split('').sort().join('')
// }

//Solution 2:
// const validAnagram = (str1, str2) => {
//   if (str1.length !== str2.length) return false

//   const lookUp = {}

//   for (const char of str1) {
//     lookUp[char] ? (lookUp[char] += 1) : (lookUp[char] = 1)
//   }

//   for (const char of str2) {
//     if (!lookUp[char]) return false
//     else lookUp[char] -= 1
//   }

//   return true
// }

// console.log(validAnagram('', '')) // true
// console.log(validAnagram('aaz', 'zza')) // false
// console.log(validAnagram('anagram', 'nagaram')) // true
// console.log(validAnagram('rat', 'car')) // false) // false
// console.log(validAnagram('awesome', 'awesom')) // false
// console.log(validAnagram('amanaplanacanalpanama', 'acanalmanplanpamana')) // false
// console.log(validAnagram('qwerty', 'qeywrt')) // true
// console.log(validAnagram('texttwisttime', 'timetwisttext')) // true

/////////////////////////////////////////////Frequency Counter - sameFrequency/////////////////////////////////////////////

// Write a function called sameFrequency. Given two positive integers, find out if the two numbers have the same frequency of digits.

// Your solution MUST have the following complexities:

// Time: O(N)

//Solution 1:
// const sameFrequency = (num1, num2) => {
//   return (
//     Number(String(num1).split('').sort().join('')) ===
//     Number(String(num2).split('').sort().join(''))
//   )
// }

//Solution 2:
// const sameFrequency = (num1, num2) => {
//   if (String(num1).length !== String(num2).length) return false
//   const lookUp = {}

//   for (const digit of String(num1)) {
//     lookUp[digit] = (lookUp[digit] || 0) + 1
//   }

//   for (const digit of String(num2)) {
//     if (!lookUp[digit]) return false
//     else {
//       lookUp[digit] -= 1
//     }
//   }

//   return true
// }

//Solution 3:
// const sameFrequency = (num1, num2) => {
//   if (String(num1).length !== String(num2).length) return false
//   const lookUp1 = {}
//   const lookUp2 = {}

//   for (const digit of String(num1)) {
//     lookUp1[digit] = (lookUp1[digit] || 0) + 1
//   }

//   for (const digit of String(num2)) {
//     lookUp2[digit] = (lookUp2[digit] || 0) + 1
//   }

//   for (const key in lookUp1) {
//     if (lookUp1[key] !== lookUp2[key]) return false
//   }

//   return true
// }

// console.log(sameFrequency(182, 281)) // true
// console.log(sameFrequency(34, 14)) // false
// console.log(sameFrequency(3589578, 5879385)) // true
// console.log(sameFrequency(22, 222)) // false

/////////////////////////////////////////////////////Multiple Pointers////////////////////////////////////////////////

//Write a function called sumZero which accepts a sorted array of integers. The function should find the first pair where the sum is 0. Return an array that includes both values that sum to zero or undefined if a pair does not exist.

// const sumZero = (arr) => {
//   if (arr === []) return undefined
//   let left = 0
//   let right = arr.length - 1

//   while (left < right) {
//     sum = arr[left] + arr[right]
//     if (sum === 0) return [arr[left], arr[right]]
//     if (sum > 0) right--
//     if (sum < 0) left++
//   }
// }

// console.log(sumZero([-3, -2, -1, 0, 1, 2, 3]))
// console.log(sumZero([-3, 0, 1, 2]))

/////////////////////////////////////////////Multiple Pointers - countUniqueValues/////////////////////////////////////////

//Implement a function called countUniqueValues, which accepts a sorted array, and counts the unique values in the array. There can be negative numbers in the array, but it will always be sorted.

// const countUniqueValues = (arr) => {
//Solution 1:
//return [...new Set(arr)].length

//Solution 2:
//   if (arr.length === 0) return 0

//   let count = 1

//   for (let i = 0; i < arr.length - 1; i++) {
//     if (arr[i] !== arr[i + 1]) count++
//   }
//   console.log(arr)
//   return count
// }

// console.log(countUniqueValues([1, 1, 1, 1, 1, 2])) // 2
// console.log(countUniqueValues([1, 2, 3, 4, 4, 4, 7, 7, 12, 12, 13])) // 7
// console.log(countUniqueValues([])) // 0
// console.log(countUniqueValues([-2, -1, -1, 0, 1])) // 4

//////////////////////////////////Frequency Counter / Multiple Pointers - areThereDuplicates///////////////////////////////

//Implement a function called, areThereDuplicates which accepts a variable number of arguments, and checks whether there are any duplicates among the arguments passed in.  You can solve this using the frequency counter pattern OR the multiple pointers pattern.

//Solution 1 (Multiple Pointers Pattern):
// const areThereDuplicates = (...args) => {
//   args.sort((a, b) => (a > b ? 1 : -1))

//   for (let i = 0; i < args.length - 1; i++) {
//     if (args[i] === args[i + 1]) return true
//   }

//   return false
// }

//Solution 2 (Frequency counter Pattern):
// const areThereDuplicates = (...args) => {
//   const lookUp = {}

//   for (const elem of args) {
//     lookUp[elem] = (lookUp[elem] || 0) + 1
//   }

//   for (const key in lookUp) {
//     if (lookUp[key] > 1) return true
//   }

//   return false
// }

//Solution 3 (Using Set):
// const areThereDuplicates = (...args) => {
//   return new Set(args).size !== args.length
// }

// console.log(areThereDuplicates(1, 2, 3)) // false
// console.log(areThereDuplicates(1, 2, 2)) // true
// console.log(areThereDuplicates('a', 'b', 'c', 'a')) // true

//////////////////////////////////////////Multiple Pointers - averagePair/////////////////////////////////////////////////

//Write a function called averagePair. Given a sorted array of integers and a target average, determine if there is a pair of values in the array where the average of the pair equals the target average. There may be more than one pair that matches the average target.

// const averagePair = (arr, target) => {
//   let left = 0
//   let right = arr.length - 1

//   while (left < right) {
//     let average = (arr[left] + arr[right]) / 2
//     if (average === target) return true
//     if (average < target) left++
//     else right--
//   }
//   return false
// }

// console.log(averagePair([1, 2, 3], 2.5)) // true
// console.log(averagePair([1, 3, 3, 5, 6, 7, 10, 12, 19], 8)) // true
// console.log(averagePair([-1, 0, 3, 4, 5, 6], 4.1)) // false
// console.log(averagePair([], 4)) // false

//////////////////////////////////////////Multiple Pointers - isSubsequence///////////////////////////////////////////////

//Write a function called isSubsequence which takes in two strings and checks whether the characters in the first string form a subsequence of the characters in the second string. In other words, the function should check whether the characters in the first string appear somewhere in the second string, without their order changing.

//Solution 1: Iterative method
// const isSubsequence = (str1, str2) => {
//   let i = 0
//   let j = 0

//   while (j < str2.length) {
//     if (i === str1.length - 1) return true
//     if (str1[i] === str2[j]) i++
//     j++
//   }
//   return false
// }

//Solution 2: Recursive method

// const isSubsequence = (str1, str2) => {
//   if (str1 === '') return true
//   if (str2 === '') return false
//   if (str1[0] === str2[0]) return isSubsequence(str1.slice(1), str2.slice(1))
//   return isSubsequence(str1, str2.slice(1))
// }

// console.log(isSubsequence('hello', 'hello world')) // true
// console.log(isSubsequence('sing', 'sting')) // true
// console.log(isSubsequence('abc', 'abracadabra')) // true
// console.log(isSubsequence('abc', 'acb')) // false (order matters)

///////////////////////////////////Sliding Window - maxSubarraySum////////////////////////////////////////////////////////

//Given an array of integers and a number, write a function called maxSubarraySum, which finds the maximum sum of a subarray with the length of the number passed to the function.

//Note that a subarray must consist of consecutive elements from the original array. In the first example below, [100, 200, 300] is a subarray of the original array, but [100, 300] is not.

// const maxSubarraySum = (arr, len) => {
//   if (arr.length < len) return null
//   let maxSum = 0
//   let tempSum = 0
//   for (let i = 0; i < len; i++) {
//     maxSum += arr[i]
//   }

//   tempSum = maxSum

//   for (let i = len; i < arr.length; i++) {
//     tempSum = tempSum - arr[i - len] + arr[i]
//     maxSum = Math.max(maxSum, tempSum)
//   }
//   return maxSum
// }

// console.log(maxSubarraySum([100, 200, 300, 400], 2)) // 700
// console.log(maxSubarraySum([1, 4, 2, 10, 23, 3, 1, 0, 20], 4)) // 39
// console.log(maxSubarraySum([-3, 4, 0, -2, 6, -1], 2)) // 5
// console.log(maxSubarraySum([3, -2, 7, -4, 1, -1, 4, -2, 1], 2)) // 5
// console.log(maxSubarraySum([2, 3], 3)) // null

///////////////////////////////////////////Sliding Window - minSubArrayLen/////////////////////////////////////////////////

//Write a function called minSubArrayLen which accepts two parameters - an array of positive integers and a positive integer.

//This function should return the minimal length of a contiguous subarray of which the sum is greater than or equal to the integer passed to the function. If there isn't one, return 0 instead.

// const minSubArrayLen = (arr, sum) => {
//   for (const elem of arr) {
//     if (elem >= sum) return 1
//   }
//   let maxSum = arr.reduce((acc, curr) => acc + curr, 0)

//   if (maxSum < sum) return 0

//   let left = 0
//   let right = arr.length - 1

//   while (maxSum > sum) {
//     if (arr[right] >= arr[left]) {
//       maxSum -= arr[left]
//       left++
//     } else {
//       maxSum -= arr[right]
//       if (maxSum > sum) right--
//     }
//   }
//   return arr.slice(left, right + 1).length
// }

// console.log(minSubArrayLen([2, 3, 1, 2, 4, 3], 7)) // 2 -> because [4,3] is the smallest subarray
// console.log(minSubArrayLen([2, 1, 6, 5, 4], 9)) // 2 -> because [5,4] is the smallest subarray
// console.log(minSubArrayLen([3, 1, 7, 11, 2, 9, 8, 21, 62, 33, 19], 52)) // 1 -> because [62] is greater than 52
// console.log(minSubArrayLen([1, 4, 16, 22, 5, 7, 8, 9, 10], 39)) // 3
// console.log(minSubArrayLen([1, 4, 16, 22, 5, 7, 8, 9, 10], 55)) // 5
// console.log(minSubArrayLen([4, 3, 3, 8, 1, 2, 3], 11)) // 2
// console.log(minSubArrayLen([1, 4, 16, 22, 5, 7, 8, 9, 10], 95)) // 0

///////////////////////////////////Sliding Window - findLongestSubstring///////////////////////////////////////////////////

//Write a function called findLongestSubstring, which accepts a string and returns the length of the longest substring with all distinct characters.

// const findLongestSubstring = (str) => {
//   if (str.length === 0) return 0
//   const seen = {}
//   let left = 0
//   let longest = 0

//   for (let i = 0; i < str.length; i++) {
//     let char = str[i]
//     if (seen[char]) {
//       left = Math.max(left, seen[char])
//     }
//     seen[char] = i + 1
//     longest = Math.max(longest, seen[char] - left)

//     // console.log('char - ', char)
//     // console.log('longest - ', longest)
//     // console.log('seen[char] - ', seen[char])
//     // console.log('left - ', left)
//     // console.log('#####################')
//   }
//   return longest
// }

// console.log(findLongestSubstring('')) // 0
// console.log(findLongestSubstring('rithmschool')) // 7
// console.log(findLongestSubstring('thisisawesome')) // 6
// console.log(findLongestSubstring('thecatinthehat')) // 7
// console.log(findLongestSubstring('bbbbbb')) // 1
// console.log(findLongestSubstring('longestsubstring')) // 8
// console.log(findLongestSubstring('thisishowwedoit')) // 6

////////////////////////////////////////////////Recursion (power)//////////////////////////////////////////////////////////

//Write a function called power which accepts a base and an exponent. The function should return the power of the base to the exponent. This function should mimic the functionality of Math.pow()  - do not worry about negative bases and exponents.

// const power = (base, exponent) => {
//   if (exponent === 0) return 1
//   return base * power(base, exponent - 1)
// }

// console.log(power(2, 3))

////////////////////////////////////////////////////factorial//////////////////////////////////////////////////////////////
//Write a function factorial which accepts a number and returns the factorial of that number. A factorial is the product of an integer and all the integers below it; e.g., factorial four ( 4! ) is equal to 24, because 4 * 3 * 2 * 1 equals 24.  factorial zero (0!) is always 1.

// const factorial = (num) => {
//   if (num === 0) return 1
//   return num * factorial(num - 1)
// }

// console.log(factorial(1)) // 1
// console.log(factorial(2)) // 2
// console.log(factorial(4)) // 24
// console.log(factorial(7)) // 5040

/////////////////////////////////////////////////////productOfArray////////////////////////////////////////////////////////

//Write a function called productOfArray which takes in an array of numbers and returns the product of them all.

// const productOfArray = (arr) => {
//   if (arr.length === 1) return arr[0]
//   return arr[0] * productOfArray(arr.slice(1))
// }

// console.log(productOfArray([4, 5, 3, 2])) //120

//////////////////////////////////////////////////////////recursiveRange///////////////////////////////////////////////////
//Write a function called recursiveRange which accepts a number and adds up all the numbers from 0 to the number passed to the function

// const recursiveRange = (num) => {
//   if (num === 0) return 0
//   return num + recursiveRange(num - 1)
// }

// console.log(recursiveRange(5)) //15

//////////////////////////////////////////////////////////fibonaci/////////////////////////////////////////////////////
//Write a recursive function called fib which accepts a number and returns the nth number in the Fibonacci sequence. Recall that the Fibonacci sequence is the sequence of whole numbers 1, 1, 2, 3, 5, 8, ... which starts with 1 and 1, and where every number thereafter is equal to the sum of the previous two numbers.

// const fibonaci = (num) => {
//   if (num === 1 || num === 2) return 1
//   return fibonaci(num - 1) + fibonaci(num - 2)
// }

// console.log(fib(4)) // 3
// console.log(fib(10)) // 55
// console.log(fib(28)) // 317811
// console.log(fib(35)) // 9227465

/////////////////////////////////////////Challenging recursion problems/////////////////////////////////////////////////////

/////////////////////////////////////////////reverse///////////////////////////////////////////////////////////////////////

//Write a recursive function called reverse which accepts a string and returns a new string in reverse.

// const reverse = (str) => {
//   if (str === '') return ''
//   return str.slice(-1) + reverse(str.slice(0, str.length - 1))
// }

// console.log(reverse('hello')) // olleh
// console.log(reverse('awesome')) // 'emosewa'
// console.log(reverse('rithmschool')) // 'loohcsmhtir'

//////////////////////////////////////////////////isPalindrome/////////////////////////////////////////////////////////////

//Write a recursive function called isPalindrome which returns true if the string passed to it is a palindrome (reads the same forward and backward). Otherwise it returns false.

// const isPalindrome = (str) => {
//   //Solution 1: iterative method
//   // let left = 0
//   // let right = str.length - 1
//   // while (left < right) {
//   //   if (str[left] === str[right]) {
//   //     left++
//   //     right--
//   //   } else return false
//   // }
//   // return true

//   if (str.length === 1) return true
//   if (str.length === 2) return str[0] === str[1]
//   if (str[0] === str.slice(-1)) return isPalindrome(str.slice(1, -1))
//   return false
// }

// console.log(isPalindrome('lol')) //true
// console.log(isPalindrome('awesome')) // false
// console.log(isPalindrome('foobar')) // false
// console.log(isPalindrome('tacocat')) // true
// console.log(isPalindrome('amanaplanacanalpanama')) // true
// console.log(isPalindrome('amanaplanacanalpandemonium')) // false

//////////////////////////////////////////////////////someRecursive///////////////////////////////////////////////////////

//Write a recursive function called someRecursive which accepts an array and a callback. The function returns true if a single value in the array returns true when passed to the callback. Otherwise it returns false.

// const someRecursive = (arr, fn) => {
//   if (arr.length === 0) return false
//   if (fn(arr[0])) return true
//   return someRecursive(arr.slice(1), fn)
// }

// // SAMPLE INPUT / OUTPUT
// const isOdd = (val) => val % 2 !== 0

// console.log(someRecursive([1, 2, 3, 4], isOdd)) // true
// console.log(someRecursive([4, 6, 8, 9], isOdd)) // true
// console.log(someRecursive([4, 6, 8], isOdd)) // false
// console.log(someRecursive([4, 6, 8], (val) => val > 10)) // false

////////////////////////////////////////////////////capitalizeFirst//////////////////////////////////////////////////////

//Write a recursive function called capitalizeFirst. Given an array of strings, capitalize the first letter of each string in the array.

// const capitalizeFirst = (arr) => {
//   let result = []
//   if (arr.length === 0) return result
//   let capitalWord = arr[0][0].toUpperCase() + arr[0].slice(1)
//   result.push(capitalWord)

//   return result.concat(capitalizeFirst(arr.slice(1)))
// }

// console.log(capitalizeFirst(['car', 'taco', 'banana'])) // ['Car','Taco','Banana']

///////////////////////////////////////////////////nestedEvenSum//////////////////////////////////////////////////////////

//Write a recursive function called nestedEvenSum. Return the sum of all even numbers in an object which may contain nested objects.

// const nestedEvenSum = (obj) => {
//   let sum = 0
//   for (const key in obj) {
//     if (typeof obj[key] === 'number' && obj[key] % 2 === 0) {
//       sum += obj[key]
//     }
//     if (typeof obj[key] === 'object') {
//       sum += nestedEvenSum(obj[key])
//     }
//   }
//   return sum
// }

// var obj1 = {
//   outer: 2,
//   obj: {
//     inner: 2,
//     otherObj: {
//       superInner: 2,
//       notANumber: true,
//       alsoNotANumber: 'yup',
//     },
//   },
// }

// var obj2 = {
//   a: 2,
//   b: { b: 2, bb: { b: 3, bb: { b: 2 } } },
//   c: { c: { c: 2 }, cc: 'ball', ccc: 5 },
//   d: 1,
//   e: { e: { e: 2 }, ee: 'car' },
// }

// console.log(nestedEvenSum(obj1)) // 6
// console.log(nestedEvenSum(obj2)) // 10

//////////////////////////////////////////capitalizeWords//////////////////////////////////////////////////////////////////

//Write a recursive function called capitalizeWords. Given an array of words, return a new array containing each word capitalized.

// const capitalizedWords = (arr) => {
//   let result = []
//   if (arr.length === 0) return result

//   result.push(arr[0].toUpperCase())
//   return result.concat(capitalizedWords(arr.slice(1)))
// }

// let words = ['i', 'am', 'learning', 'recursion']
// console.log(capitalizedWords(words)) // ['I', 'AM', 'LEARNING', 'RECURSION']

///////////////////////////////////////////////stringifyNumbers/////////////////////////////////////////////////////////

//Write a function called stringifyNumbers which takes in an object and finds all of the values which are numbers and converts them to strings. Recursion would be a great way to solve this!

// const stringifyNumbers = (obj) => {
//   let result = {}

//   for (const key in obj) {
//     if (typeof obj[key] === 'number') {
//       result[key] = obj[key].toString()
//     } else if (typeof obj[key] === 'object' && !Array.isArray(obj[key])) {
//       result[key] = stringifyNumbers(obj[key])
//     } else {
//       result[key] = obj[key]
//     }
//   }
//   return result
// }

// let obj = {
//   num: 1,
//   test: [],
//   data: {
//     val: 4,
//     info: {
//       isRight: true,
//       random: 66,
//     },
//   },
// }

// console.log(stringifyNumbers(obj))

// /*
// {
//     num: "1",
//     test: [],
//     data: {
//         val: "4",
//         info: {
//             isRight: true,
//             random: "66"
//         }
//     }
// }
// */

////////////////////////////////////////////////collectStrings/////////////////////////////////////////////////////////////

//Write a function called collectStrings which accepts an object and returns an array of all the values in the object that have a typeof string

// const collectStrings = (obj) => {
//   let result = []

//   for (const key in obj) {
//     if (typeof obj[key] === 'string') {
//       result.push(obj[key])
//     }
//     if (typeof obj[key] === 'object' && !Array.isArray(obj[key])) {
//       //result = result.concat(collectStrings(obj[key]))
//       return result.concat(collectStrings(obj[key]))
//     }
//   }
//   return result
// }

// const obj = {
//   stuff: 'foo',
//   data: {
//     val: {
//       thing: {
//         info: 'bar',
//         moreInfo: {
//           evenMoreInfo: {
//             weMadeIt: 'baz',
//           },
//         },
//       },
//     },
//   },
// }

// console.log(collectStrings(obj)) // ["foo", "bar", "baz"])

///////////////////////////////////////////flatten////////////////////////////////////////////////////////////////////////

//Write a recursive function called flatten which accepts an array of arrays and returns a new array with all values flattened.

// const flatten = (arr) => {

//Solution 1:using flat ES6 method
//return arr.flat(Infinity)

//Solution 2:using ES6 flatMap method & recursion
// return arr.flatMap((elem) => (Array.isArray(elem) ? flatten(elem) : elem))

//Solution 3:using reduce & recursion
// return arr.reduce(
//   (acc, curr) => acc.concat(Array.isArray(curr) ? flatten(curr) : curr),
//   []
// )

//Solution 4:using while loop
//   while (arr.some((elem) => Array.isArray(elem))) {
//     arr = [].concat(...arr)
//   }
//   return arr
// }

// console.log(flatten([1, 2, 3, [4, 5]])) // [1, 2, 3, 4, 5]
// console.log(flatten([1, [2, [3, 4], [[5]]]])) // [1, 2, 3, 4, 5]
// console.log(flatten([[1], [2], [3]])) // [1,2,3]
// console.log(flatten([[[[1], [[[2]]], [[[[[[[3]]]]]]]]]])) // [1,2,3]

///////////////////////////////////////////////generate random numbers/////////////////////////////////////////////////////
// Math.floor(Math.random() * (max - min + 1)) + min
// const random = Array.from(
//   { length: 10 },
//   () => Math.floor(Math.random() * (25 - 10 + 1)) + 10
// )
//console.log(random)

/////////////////////////////////////////////////Binary Search/////////////////////////////////////////////////////////////

//Write a function called binarySearch which accepts a sorted array and a value and returns the index at which the value exists. Otherwise, return -1.

//This algorithm should be more efficient than linearSearch - you can read how to implement it here - https://www.khanacademy.org/computing/computer-science/algorithms/binary-search/a/binary-search and here - https://www.topcoder.com/community/data-science/data-science-tutorials/binary-search/

//Big O --> O(log n)
//Best case --> O(1), constant time

// const binarySearch = (arr, num) => {
//   let left = 0
//   let right = arr.length - 1
//   while (left <= right) {
//     let midpoint = Math.floor((left + right) / 2)

//     if (arr[midpoint] === num) return midpoint
//     if (arr[midpoint] > num) right = midpoint - 1
//     else left = midpoint + 1
//   }
//   return -1
// }

// console.log(binarySearch([11, 13, 14, 19, 20, 22, 23, 24, 29, 32], 32)) //9
// console.log(binarySearch([1, 2, 3, 4, 5], 2)) // 1
// console.log(binarySearch([1, 2, 3, 4, 5], 3)) // 2
// console.log(binarySearch([1, 2, 3, 4, 5], 5)) // 4
// console.log(binarySearch([1, 2, 3, 4, 5], 6)) // -1
// console.log(
//   binarySearch(
//     [
//       5, 6, 10, 13, 14, 18, 30, 34, 35, 37, 40, 44, 64, 79, 84, 86, 95, 96, 98,
//       99,
//     ],
//     10
//   )
// ) // 2
// console.log(
//   binarySearch(
//     [
//       5, 6, 10, 13, 14, 18, 30, 34, 35, 37, 40, 44, 64, 79, 84, 86, 95, 96, 98,
//       99,
//     ],
//     95
//   )
// ) // 16
// console.log(
//   binarySearch(
//     [
//       5, 6, 10, 13, 14, 18, 30, 34, 35, 37, 40, 44, 64, 79, 84, 86, 95, 96, 98,
//       99,
//     ],
//     100
//   )
// ) // -1

///////////////////////////////////Bubble sort (largest value bubbles up to the top (asc to desc))//////////////////////
//push largest value at the end
//Usecase:- if the input data is nearly sorted

//Big O --> O(n**2)
//Best case --> O(n)

//using recursion but unoptimized ??
// const bubbleSort = (arr) => {
//   let result = []
//   if (arr.length === 0) return []
//   for (let i = 0; i < arr.length - 1; i++) {
//     if (arr[i] < arr[i + 1]) {
//       ;[arr[i + 1], arr[i]] = [arr[i], arr[i + 1]]
//       noSwaps = false
//     }
//   }
//   result.push(arr[arr.length - 1])
//   return result.concat(bubbleSort(arr.slice(0, -1)))
// }

//Optimized solution, covers the case where the input arr is almost sorted
// const bubbleSort = (arr) => {
//   let noSwap = true
//   for (let i = arr.length; i > 0; i--) {
//     for (let j = 0; j < i; j++) {
//       if (arr[j] > arr[j + 1]) {
//         ;[arr[j], arr[j + 1]] = [arr[j + 1], arr[j]]
//         noSwap = false
//       }
//     }
//     if (noSwap) break
//   }
//   return arr
// }
// console.log(bubbleSort([20, 10, 1, 8, -5, 15, 3, 5, 0]))

///////////////////////////Selection sort (select the min value and put it at the start)///////////////////////////////////
//Big O --> O(n**2)

//usecase: where writing to memory is crucial(actually doing the swap) because the no of swaps is lesser than bubble sort,,
//so this sort uses less memory compared to bubble sort

// const selectionSort = (arr) => {
//   for (let i = 0; i < arr.length-1; i++) {
//     let lowest = i
//     for (let j = i + 1; j < arr.length; j++) {
//       if (arr[j] < arr[lowest]) {
//         lowest = j
//       }
//     }
//     if (lowest !== i) {
//       ;[arr[i], arr[lowest]] = [arr[lowest], arr[i]]
//     }
//   }
//   return arr
// }

// console.log(selectionSort([20, 10, 1, 8, -5, 15, 3, 5, 0]))

///////////////Insertion sort (builds up the sort gradually creating a larger left half which is always sorted)////////////

//Big O --> O(n**2),, O(n) if nearly sorted
//usecase - where data is coming live (like data streaming) and the data needs to be sorted as it comes

// const insertionSort = (arr) => {
//   for (let i = 1; i < arr.length; i++) {
//     let currentValue = arr[i]
//     for (var j = i - 1; j >= 0 && arr[j] > currentValue; j--) {
//       arr[j + 1] = arr[j]
//     }
//     arr[j + 1] = currentValue
//   }
//   return arr
// }

// console.log(insertionSort([20, 10, 1, 8, -5, 15, 3, 5, 0]))

////Below algos use - Divide & Conquer technique

// 1. Binary Search
// 2. Merge sort
// 3. Quick sort

//////////////////////////////////////////////////////Merge sort////////////////////////////////////////////////////////////

//Big O --> O(n logn)

// const merge = (arr1, arr2) => {
//   let results = []
//   let i = 0
//   let j = 0

//   while (i < arr1.length && j < arr2.length) {
//     if (arr2[j] > arr1[i]) {
//       results.push(arr1[i])
//       i++
//     } else {
//       results.push(arr2[j])
//       j++
//     }
//   }

//   while (i < arr1.length) {
//     results.push(arr1[i])
//     i++
//   }

//   while (j < arr2.length) {
//     results.push(arr2[j])
//     j++
//   }

//   return results
// }

// // console.log(merge([], [2, 7, 8, 11, 18, 20]))

// const mergeSort = (arr) => {
//   if (arr.length <= 1) return arr
//   let midpoint = Math.floor(arr.length / 2)
//   let left = mergeSort(arr.slice(0, midpoint))
//   let right = mergeSort(arr.slice(midpoint))
//   return merge(left, right)
// }

// console.log(mergeSort([45, 10, -6, 28, 63, 10, 19, 22]))

//////////////////////////////////////////////////////Quick sort///////////////////////////////////////////////////////////
//Big O --> O(nlogn),,,,, O(n ** 2) if the array is already sorted

// const pivot = (arr) => {
//   let pivot = arr[0]
//   let swapIndex = 0

//   const swap = (arr, i, j) => {
//     ;[arr[i], arr[j]] = [arr[j], arr[i]]
//   }

//   for (let i = 1; i < arr.length; i++) {
//     if (arr[i] < pivot) {
//       swapIndex++
//       swap(arr, swapIndex, i)
//     }
//   }
//   swap(arr, 0, swapIndex)
//   return swapIndex
// }

// const quickSort = (arr, left = 0, right = arr.length - 1) => {
//   if (left < right) {
//     let pivotIndex = pivot(arr)
//     quickSort(arr, left, pivotIndex - 1)
//     quickSort(arr, pivotIndex + 1, right)
//   }
//   return arr
// }

// // console.log(pivot([45, 10, -6, 28, 63, 10, 19, 22]))
// console.log(quickSort([45, 10, -6, 28, 63, 10, 19, 22]))

//////////////////////////////////////////////////////Radix sort///////////////////////////////////////////////////////////
//Big O --> O(nk), theoretically ...................
//TO DO - Update the logic to include negative numbers

// const getDigit = (num, i) => {
//   const digit = Number(num.toString().split('').reverse()[i])
//   return isNaN(digit) ? 0 : digit
// }

// const digitCount = (num) => num.toString().split('').length

// const mostDigits = (nums) => {
//   let maxDigits = 0
//   for (let i = 0; i < nums.length; i++) {
//     maxDigits = Math.max(maxDigits, digitCount(nums[i]))
//   }
//   return maxDigits
// }

// const radixSort = (nums) => {
//   for (let i = 0; i < mostDigits(nums); i++) {
//     let digitBuckets = Array.from({ length: 10 }, () => [])
//     for (j = 0; j < nums.length; j++) {
//       let digit = getDigit(nums[j], i)
//       digitBuckets[digit].push(nums[j])
//     }
//     nums = [].concat(...digitBuckets)
//   }
//   return nums
// }

// console.log(radixSort([23, 345, 5467, 12, 2345, 9852]))
// console.log(radixSort([23, 345, -5467, 12, 2345, 9852]))

///////////////////////////////////////////////SinglyLinkedList///////////////////////////////////////////////////////////

// class Node {
//   constructor(value) {
//     this.value = value
//     this.next = null
//   }
// }

// class SinglyLinkedList {
//   constructor() {
//     this.head = null
//     this.tail = null
//     this.length = 0
//   }
//   push(val) {
//     let newNode = new Node(val)
//     if (!this.head) {
//       this.head = newNode
//       this.tail = this.head
//     } else {
//       this.tail.next = newNode
//       this.tail = newNode
//     }
//     this.length++
//     return this
//   }

//   pop() {
//     if (!this.head) return undefined
//     let current = this.head
//     let newTail = current
//     while (current.next) {
//       newTail = current
//       current = current.next
//     }
//     this.tail = newTail
//     this.tail.next = null
//     this.length--
//     if (this.length === 0) {
//       this.head = null
//       this.tail = null
//     }
//     return current //returning the node that was popped
//   }

//   shift() {
//     if (!this.head) return undefined
//     let currentHead = this.head
//     this.head = currentHead.next
//     this.length--
//     if (this.length === 0) {
//       this.tail = null
//     }
//     return currentHead
//   }

//   unshift(val) {
//     let newNode = new Node(val)
//     if (!this.head) {
//       this.head = newNode
//       this.tail = this.head
//     } else {
//       newNode.next = this.head
//       this.head = newNode
//     }
//     this.length++
//     return this
//   }

//   get(index) {
//     if (index < 0 || index >= this.length) return null
//     let counter = 0
//     let current = this.head
//     // while (current) {
//     //   if (counter === index) {
//     //     return current
//     //   }
//     //   counter++
//     //   current = current.next
//     // }
//     while (counter !== index) {
//       current = current.next
//       counter++
//     }
//     return current
//   }

//   set(index, val) {
//     let nodeToUpdate = this.get(index)
//     if (nodeToUpdate) {
//       nodeToUpdate.value = val
//       return true
//     }
//     return false
//   }

//   insert(index, val) {
//     if (index < 0 || index > this.length) return false
//     if (index === this.length) return !!this.push(val)
//     if (index === 0) return !!this.unshift(val)

//     let newNode = new Node(val)
//     let previous = this.get(index - 1)
//     let tempNode = previous.next
//     previous.next = newNode
//     newNode.next = tempNode
//     this.length++
//     return true
//   }

//   remove(index) {
//     if (index < 0 || index >= this.length) return undefined
//     if (index === this.length - 1) return this.pop()
//     if (index === 0) return this.shift()

//     let previous = this.get(index - 1)
//     let removed = previous.next
//     previous.next = removed.next
//     this.length--
//     return removed
//   }

//   reverse() {
//     let node = this.head
//     this.head = this.tail
//     this.tail = node

//     let next
//     let previous = null

//     for (let i = 0; i < this.length; i++) {
//       next = node.next
//       node.next = previous
//       previous = node
//       node = next
//     }
//     return this
//   }

//   print() {
//     let arr = []
//     let current = this.head
//     while (current) {
//       arr.push(current.value)
//       current = current.next
//     }
//     return arr
//   }
// }

// let linkedList = new SinglyLinkedList()
// // console.log(linkedList)
// console.log(linkedList.push(1))
// console.log(linkedList.push(2))
// console.log(linkedList.push(3))
// console.log(linkedList.set(1, 'HI'))
// console.log(linkedList.get(1))
// console.log(linkedList.print())
// console.log(linkedList.reverse())
// console.log(linkedList.print())
// console.log(linkedList.pop())
// console.log(linkedList.pop())
// console.log(linkedList.pop())
// console.log(linkedList)
// console.log(linkedList.unshift(5))

///////////////////////////////////////////////Doubly Linked List/////////////////////////////////////////////////////////

// class Node {
//   constructor(val) {
//     this.val = val
//     this.next = null
//     this.prev = null
//   }
// }

// class DoublyLinkedList {
//   constructor() {
//     this.head = null
//     this.tail = null
//     this.length = 0
//   }

//   push(val) {
//     let newNode = new Node(val)
//     if (this.length === 0) {
//       this.head = newNode
//       this.tail = newNode
//     } else {
//       this.tail.next = newNode
//       newNode.prev = this.tail
//       this.tail = newNode
//     }
//     this.length++
//     return this
//   }

//   pop() {
//     if (this.tail === null) return undefined
//     let oldTail = this.tail
//     if (this.length === 1) {
//       this.head = null
//       this.tail = null
//     } else {
//       this.tail = oldTail.prev
//       this.tail.next = null
//       oldTail.prev = null
//     }
//     this.length--
//     return oldTail
//   }

//   shift() {
//     if (!this.head) return undefined
//     let oldHead = this.head
//     if (this.length === 1) {
//       this.head = null
//       this.tail = null
//     } else {
//       this.head = oldHead.next
//       this.head.prev = null
//       oldHead.next = null
//     }
//     this.length--
//     return oldHead
//   }

//   unshift(val) {
//     let newNode = new Node(val)
//     if (this.length === 0) {
//       this.head = newNode
//       this.tail = newNode
//     } else {
//       this.head.prev = newNode
//       newNode.next = this.head
//       this.head = newNode
//     }
//     this.length++
//     return this
//   }

//   get(index) {
//     if (index < 0 || index >= this.length) return null
//     let current
//     if (index <= this.length / 2) {
//       let count = 0
//       current = this.head
//       while (count !== index) {
//         current = current.next
//         count++
//       }
//     } else {
//       let count = this.length - 1
//       current = this.tail
//       while (count !== index) {
//         current = current.prev
//         count--
//       }
//     }
//     return current
//   }

//   set(index, val) {
//     let setNode = this.get(index)
//     if (setNode !== null) {
//       setNode.val = val
//       return true
//     }
//     return false
//   }

//   insert(index, val) {
//     if (index < 0 || index > this.length) return false
//     if (index === 0) return !!this.unshift(val)
//     if (index === this.length) return !!this.push(val)

//     let newNode = new Node(val)
//     let prevNode = this.get(index - 1)
//     let nextNode = prevNode.next

//     ;(prevNode.next = newNode), (newNode.prev = prevNode)
//     ;(newNode.next = nextNode), (nextNode.prev = newNode)

//     this.length++
//     return true
//   }

//   remove(index) {
//     if (index < 0 || index >= this.length) return undefined
//     if (index === 0) return this.shift()
//     if (index === this.length - 1) return this.pop()

//     let removedNode = this.get(index)
//     let prevNode = removedNode.prev
//     let nextNode = removedNode.next

//     prevNode.next = nextNode
//     nextNode.prev = prevNode

//     removedNode.next = null
//     removedNode.prev = null

//     this.length--
//     return removedNode
//   }

//   reverse() {
//     let temp = null
//     let current = this.head
//     while (current) {
//       temp = current.prev
//       current.prev = current.next
//       current.next = temp
//       current = current.prev
//     }
//     // if (this.length > 1) {
//     //   this.tail = this.head
//     // }

//     // if (temp) {
//     //   this.head = temp.prev
//     // }

//     if (this.length > 1) {
//       this.tail = this.head
//       this.head = temp.prev
//     }
//     return this
//   }

//   print() {
//     let arr = []
//     let current = this.head
//     while (current) {
//       arr.push(current.val)
//       current = current.next
//     }
//     return arr
//   }
// }

// let dll = new DoublyLinkedList()
// dll.push(1)
// dll.push(2)
// dll.push(3)
// dll.push(4)
// dll.push(5)
// dll.push(6)
// dll.push(7)

// dll.reverse()
// console.log(dll.print())

///////////////////////////////////////////Stacks & Queues/////////////////////////////////////////////////////////////////

// class Node {
//   constructor(value) {
//     this.value = value
//     this.next = null
//   }
// }

// class Stack {
//   constructor() {
//     this.first = null
//     this.last = null
//     this.size = 0
//   }

//   push(val) {
//     let newNode = new Node(val)
//     if (!this.first) {
//       this.first = newNode
//       this.last = newNode
//     } else {
//       let temp = this.first
//       this.first = newNode
//       this.first.next = temp
//     }
//     return ++this.size
//   }

//   pop() {
//     if (!this.first) return null
//     let temp = this.first
//     if (this.first === this.last) {   // if(this.size === 1)
//       this.last = null
//     }
//     this.first = this.first.next
//     this.size--
//     return temp.value
//   }
// }

// let stack = new Stack()
// console.log(stack.push(1))
// console.log(stack.push(2))
// console.log(stack.push(3))
// console.log(stack)

// class Node {
//   constructor(value) {
//     this.value = value
//     this.next = null
//   }
// }

// class Queue {
//   constructor() {
//     this.first = null
//     this.last = null
//     this.size = 0
//   }

//   enqueue(val) {
//     let newNode = new Node(val)
//     if (!this.first) {
//       this.first = newNode
//       this.last = newNode
//     } else {
//       this.last.next = newNode
//       this.last = newNode
//     }
//     return ++this.size
//   }

//   dequeue() {
//     if (!this.first) return null
//     let temp = this.first
//     if (this.first === this.last) {
//       // if(this.size === 1)
//       this.last = null
//     }
//     this.first = this.first.next
//     this.size--
//     return temp.value
//   }
// }

//////////////////////////////////////////////////////Binary Search Trees (BST)////////////////////////////////////////////

class Node {
  constructor(value) {
    this.value = value
    this.right = null
    this.left = null
    this.count = 1
  }
}

class BinarySearchTree {
  constructor() {
    this.root = null
  }

  insert(value) {
    let newNode = new Node(value)
    if (this.root === null) {
      this.root = newNode
      return this
    }
    let current = this.root
    while (true) {
      if (value === current.value) {
        current.count++
        return 'Duplicate node'
      }
      if (value < current.value) {
        if (current.left === null) {
          current.left = newNode
          return this
        }
        current = current.left
      } else {
        if (current.right === null) {
          current.right = newNode
          return this
        }
        current = current.right
      }
    }
  }

  find(value) {
    if (this.root === null) return undefined
    let current = this.root
    let found = false
    while (current && !found) {
      if (value < current.value) current = current.left
      else if (value > current.value) current = current.right
      else found = true
    }
    if (!found) return undefined
    return current
  }

  // contains(value) {
  //   if (this.root === null) return false
  //   let current = this.root
  //   let found = false
  //   while (current && !found) {
  //     if (value < current.value) current = current.left
  //     else if (value > current.value) current = current.right
  //     else return true
  //   }
  //   return false
  // }

  BFS() {
    //breadth first search
    let node = this.root
    let visited = []
    let queue = []
    queue.push(node)
    while (queue.length) {
      node = queue.shift()
      visited.push(node.value)
      if (node.left) queue.push(node.left)
      if (node.right) queue.push(node.right)
    }
    return visited
  }

  DFS_preOrder() {
    let visited = []

    function traverse(node) {
      visited.push(node.value)
      if (node.left) traverse(node.left)
      if (node.right) traverse(node.right)
    }

    traverse(this.root) ///starts from root node,, can be changed this if you wanna start from some other node
    return visited
  }

  DFS_postOrder() {
    let visited = []

    function traverse(node) {
      if (node.left) traverse(node.left)
      if (node.right) traverse(node.right)
      visited.push(node.value)
    }

    traverse(this.root) ///starts from root node,, can be changed this if you wanna start from some other node
    return visited
  }

  DFS_inOrder() {
    let visited = []

    function traverse(node) {
      node.left && traverse(node.left)
      visited.push(node.value)
      node.right && traverse(node.right)
    }

    traverse(this.root) ///starts from root node,, can be changed this if you wanna start from some other node
    return visited
  }
}

let bst = new BinarySearchTree()
bst.insert(10)
bst.insert(6)
bst.insert(15)
bst.insert(3)
bst.insert(8)
bst.insert(20)

//console.log(bst)
console.log(bst.DFS_inOrder())
