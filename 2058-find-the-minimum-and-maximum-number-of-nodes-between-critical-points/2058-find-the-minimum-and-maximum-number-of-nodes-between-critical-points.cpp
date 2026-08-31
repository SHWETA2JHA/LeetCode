class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> critical;

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        int i = 1;

        while (next != nullptr) {

            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {

                critical.push_back(i);
            }

            prev = curr;
            curr = next;
            next = next->next;
            i++;
        }

        if (critical.size() < 2)
            return {-1, -1};

        int mini = INT_MAX;

        for (int i = 1; i < critical.size(); i++) {
            mini = min(mini, critical[i] - critical[i - 1]);
        }

        int maxi = critical.back() - critical.front();

        return {mini, maxi};
    }
};