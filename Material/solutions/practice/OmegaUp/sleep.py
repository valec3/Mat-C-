def find3Numbers(arr, sum):
    count=0
    # Fix the first element as arr[i]
    for i in range(len(arr) - 2):

        # Create a set to store potential second elements that complement the desired sum
        s = set()

        # Calculate the current sum needed to reach the target sum
        curr_sum = sum - arr[i]

        # Iterate through the subarray arr[i+1:]
        for j in range(i + 1, len(arr)):

            # Calculate the required value for the second element
            required_value = curr_sum - arr[j]

            # Check if the required value is present in the set
            if required_value in s:
                count+=1

            # Add the current element to the set for future complement checks
            s.add(arr[j])

    # If no triplet is found, return False
    return count

# Driver program to test above function
if __name__ == "__main__":
    n = int(input())
    arr =   [int(input().strip()) for _ in range(n)]
    target_sum = 5000

    resp = find3Numbers(arr, target_sum)
    print(resp)