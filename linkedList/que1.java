/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

// Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

// After doing so, return the head of the final linked list.  You may return any such answer.

 

// (Note that in the examples below, all sequences are serializations of ListNode objects.)
class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        HashMap<Integer, ListNode> valueMapping = new HashMap<>();
        int runningSum = 0;
        ListNode ansHead = new ListNode(0, head);
        head = ansHead;
        while(head != null)
        {
            runningSum += head.val;
            if(valueMapping.containsKey(runningSum))
            {
                ListNode tempNode = valueMapping.get(runningSum);
                head = tempNode.next;
                int p = runningSum + head.val;
                while(runningSum != p)
                {
                   valueMapping.remove(p);
                   head = head.next;
                   p += head.val;
                }
                tempNode.next = head.next;
            }
            else
            {
                valueMapping.put(runningSum, head);
            }
            head = head.next;
        }
        return ansHead.next;
        
    }
}