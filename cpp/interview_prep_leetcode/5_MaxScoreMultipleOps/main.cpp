#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define MAX_SIZE_MULTIPLIERS (1000)
static int maxScore[MAX_SIZE_MULTIPLIERS][MAX_SIZE_MULTIPLIERS];

class Solution
{

private:

    vector<int> nums;
    int szOfNums;
    vector<int> multipliers;
    int szOfMultipliers;
    /** top-down function to recursively find the maximum score for
     *  each set of nums and multipliers.
     * 
     * state variables: i- the total number of multiplications done so far.
     *                  left-total number of left values (of nums) used in the
     *                       mutlipliactions.
     *  base condition: when all multipliers are exhauseted, then you return 0.
     */
    int dp(uint8_t i, uint8_t left)
    {
        int retval = 0;

        int right = szOfNums - (i - left) - 1;

        if (i == szOfMultipliers)
        {
            // base condition
            retval = 0;
        }
        else
        {
            if (0 == maxScore[i][left])
            {
                int leftProduct = nums[left] * multipliers[i];
                int rightProduct = nums[right] * multipliers[i];
                // recurrence relation
                maxScore[i][left] = max(leftProduct + dp(i + 1, left + 1),
                                        rightProduct + dp(i + 1, left));
            }
            retval = maxScore[i][left];
        }
        return retval;
    }

public:
    Solution(vector<int> &nums, vector<int> &multipliers)
    {
        this->nums = nums;
        szOfNums = nums.size();
        this->multipliers = multipliers;
        szOfMultipliers = multipliers.size();
    }

    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int retval = -1;
        for (int i = 0; i < szOfMultipliers; i++)
            for (int j = 0; j < szOfMultipliers; j++)
                maxScore[i][j] = 0;

        retval = dp(0, 0);

        return retval;
    }
};

int main(void)
{
    // vector<int> nums = {1, 2, 3};
    // vector<int> multipliers = {3, 2, 1};

    // vector<int> nums = {-5, -3, -3, -2, 7, 1};
    // vector<int> multipliers = {-10, -5, 3, 4, 6};

    // // Code does not work for large inputs - segmentation fault! probably stack is
    // // overwhelmed!!
    //    static vector<int> nums = {-868, 482, -853, 618, 814, -407, -242, -35, 581, 597, 656, 660, 87, 797, -675, 81, -671, -264,
    //                         -189, 402, 252, -454, 540, 814, 678, -869, -416, -197, -787, -27, -31, -975, 300, 824, -160,
    //                         963, -527, 98, 342, 504, 237, -16, 235, -648, 217, 686, -922, -571, -623, 721, -902, 635, 895,
    //                         954, 454, -982, -270, 661, 327, 433, 241, -553, 227, 848, 696, 129, -520, 840, 594, -788, 489,
    //                         255, -483, -398, 693, -924, 467, -439, 872, 885, 206, 21, -907, -268, 953, -385, -275, 774,
    //                         -294, 347, -651, -73, 150, 641, 560, -228, -587, -464, -314, 906, 895, -410, 598, -337, -449,
    //                         -998, -935, -962, -886, 275, -802, 406, 683, 465, 275, -610, -370, 11, 437, -123, -534, 72,
    //                         -949, -333, -678, -844, 979, -350, 459, -478, 678, 492, -779, -514, -570, 128, 338, 935, -392,
    //                         -384, 930, -394, 804, -406, 107, -90, 869, 604, -801, 937, -662, 935, -440, 234, 997, -291, 108,
    //                         -940, 504, 82, 816, -928, -13, 67, -975, -64, -514, -806, -910, 264, 59, 202, -656, 411, 311,
    //                         -392, -687, 18, 486, -804, -400, -727, -992, 948, -982, 830, 150, 857, 94, 104, -280, 935, 246,
    //                         -919, 374, -939, -977, 272, 132, 308, 472, -823, -553, -268, -930, 275, -236, 328, -874, 811,
    //                         304, 719, -325, 639, -987, 282, -899, 593, -515, -962, -353, -44, -336, 321, 464, -465, -886,
    //                         498, -942, -585, 96, -653, 748, 925, 880, 490, -42, -445, 323, 70, -3, 772, -122, -856, 168,
    //                         861, -919, -43, -436, 178, -68, -819, 966, 906, 86, -470, 850, -609, -218, -642, 243, 729, 28,
    //                         -851, 982, 883, -861, -613, -727, 99, 582, 278, 225, -746, 809, 564, -759, 769, -52, 602, 206,
    //                         667, 76, 268, -389, 909, -815, -718, 445, -959, -53, -583, 248, -213, 294, -307, -926, 951, 483,
    //                         126, 551, -973, -619, 872, -354, -303, 202, 112, -505, 251, -35, 412, 613, 587, -793, 222, 695,
    //                         282, 809, -655, -55, 95, 622, -365, -685, -358, -826, 392, -251, 915, 147, 915, -52, -632, 818,
    //                         -852, 809, 868, -925, -798, -46, 430, 860, -186, -651, 992, -256, -256, -751, -121, -551, -92,
    //                         515, 175, -568, -527, -994, 783, 838, -69, -826, -872, 442, -844, -117, 965, 219, -833, 20,
    //                         -589, -222, 431, -74, 633, -438, -614, -343, 163, -444, -594, -868, -5, -802, -516, 723, -716,
    //                         -399, 616, -857, -227, 395, -775, -361, 361, -999, 146, -982, -254, -801, 487, -692, -654, 633,
    //                         440, -358, 329, 372, 877, 341, 261, -938, 208, -830, -292, -221, 806, -502, -527, 598, -57, 517,
    //                          -472, 678, 553, -763, 56, 370, -115, 473, 404, 299, 990, 753, -997, 102, -463, -371, -386, -659,
    //                           60, 254, -899, 830, 620, -583, 219, 623, 501, 893, -878, -772, 847, 785, -340, -86, 84, 124,
    //                           -301, -246, 427, -518, -697, 777, -335, 573, -656, -444, -426, -75, -693, -857, -243, 216,
    //                           -246, -722, 29, 474, 722, 251, 459, -700, 67, -880, 81, -769, -788, 425, 48, 930, 549, 599,
    //                           -24, -265, -929, -914, 2, 841, 222, 380, 78, 879};
    //     static vector<int> multipliers = {865, -808, -661, -648, -772, 396, -643, 272, -743, -984, -529, -925, 50, 10, 880, -310,
    //                                -927, -370, -54, 245, 41, -107, 683, -586, 846, -978, -877, 164, 265, -789, -994, -405,
    //                                383, -700, -824, -217, -682, -307, -805, 720, -830, -247, 458, 348, 404, 329, -555, 905,
    //                                572, 466, 274, 578, -257, 796, -745, -662, -85, -723, -597, -152, 123, -211, -666, -613,
    //                                -154, 755, 923, -956, 577, -614, 521, 743, 926, 135, 715, 248, 685, 755, -912, 511, 159,
    //                                 369, 299, -940, 179, -962, 477, -405, -219, 705, 34, 12, 898, -497, -768, 683, -601,
    //                                 -617, -892, 577, 528, 397, -784, -590, 898, -172, 610, 342, 668, -50, 156, -968, -492,
    //                                 981, -725, 612, 375, 343, -616, -832, -326, -126, -357, 52, -655, -917, 489, 501, 883,
    //                                 -899, 228, 886, -706, -8, -17, -174, -49, 442, -23, -510, -886, 750, -96, -76, 384,
    //                                 -511, 43, 305, -134, -599, -825, -489, -3, 142, 95, -159, 537, -269, -873, 709, 783,
    //                                 200, -997, -525, 183, 552, -346, 321, -541, 658, 634, -597, 148, 969, 581, 115, -795,
    //                                 -358, -31, 355, 33, 593, 333, -93, 536, 576, 226, -805, 315, 833, 833, -11, -159, 30,
    //                                 -184, -521, -983, 128, 164, 744, 866, -390, 65, 410, -524, 717, -353, -271, 93, 881,
    //                                 590, 622, 425, 241, -912, -37, 971, 21, 813, -447, -936, -10, -63, -808, -232, -760,
    //                                 107, -382, 104, -411, -290, -209, -392, -41, 660, -748, -988, -598, -933, -342, 361,
    //                                 -185, 575, -2, 725, -531, -873, -249, -169, -567, 204, 836, -302, 745, -83, 512, -721,
    //                                 387, 675, -272, -469, -804, 472, 569, -437, -10, 927, -258, -159, -306, -419, -222,
    //                                 -133, 78, -796, -533, 903, -805, 175, -827, 661, -720, 365, 711, -198, -228, 275, 66,
    //                                 743, -822, 576, 996, 553, -65, -9, 106, 233, 792, -941, -649, 625, -851, -217, -289,
    //                                 -864, -455, -145, -534, 112, -194, 899, 199, 542, 138, -70, -71, 24, -447, -876, 169,
    //                                 -333, 0, -526, 798, 908, -934, -320, -215, -9, -54, -569, 189, -583, -865, -382, -361,
    //                                 -579, 25, 440, -656, -649, 237, 445, 199, 726, -502, 710, 107, 408, 290, -603, -832,
    //                                 -527, 878, -840, -455, -479, 542, -645, -400, 268, -183, 558, -283, 158, 879, 377, 529,
    //                                 508, 936, 651, -498, 55, -355, 405, 181, 399, 611, -321, 264};

    int m = multipliers.size();
    Solution s(nums, multipliers);
    cout << "Max score after " << m << " ops = " << s.maximumScore(nums, multipliers) << endl;
    return 0;
}