class Solution {
public:
    string smallestNumber(string num, long long t) {
        int digitPrimePower[10][4] = {
            {0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {2,0,0,0},
            {0,0,1,0}, {1,1,0,0}, {0,0,0,1}, {3,0,0,0}, {0,2,0,0}
        };

        auto subtractPower = [](array<int,4> first, array<int,4> second) {
            for (int i = 0; i < 4; i++) first[i] = max(0, first[i] - second[i]);
            return first;
        };

        auto coversRequirement = [](array<int,4> have, array<int,4> need) {
            for (int i = 0; i < 4; i++) if (have[i] < need[i]) return false;
            return true;
        };

        auto cheapestDigits = [](array<int,4> power) {
            array<int,10> digitCount = {};
            int eightCount = power[0] / 3;
            int leftoverTwo = power[0] % 3;
            int nineCount = power[1] / 2;
            int leftoverThree = power[1] % 2;
            int fourCount = leftoverTwo / 2;
            int twoCount = leftoverTwo % 2;
            int sixCount = 0;
            if (twoCount == 1 && leftoverThree == 1) {
                twoCount = 0; leftoverThree = 0; sixCount = 1;
            }
            if (leftoverThree == 1 && fourCount == 1) {
                twoCount = 1; sixCount = 1; leftoverThree = 0; fourCount = 0;
            }
            digitCount[2] = twoCount;
            digitCount[3] = leftoverThree;
            digitCount[4] = fourCount;
            digitCount[5] = power[2];
            digitCount[6] = sixCount;
            digitCount[7] = power[3];
            digitCount[8] = eightCount;
            digitCount[9] = nineCount;
            return digitCount;
        };

        auto totalDigits = [](array<int,10> digitCount) {
            int sum = 0;
            for (int digit = 2; digit <= 9; digit++) sum += digitCount[digit];
            return sum;
        };

        auto buildString = [](array<int,10> digitCount) {
            string result = "";
            for (int digit = 2; digit <= 9; digit++) {
                result += string(digitCount[digit], char('0' + digit));
            }
            return result;
        };

        array<int,4> requiredPower = {0,0,0,0};
        int primes[4] = {2,3,5,7};
        long long tCopy = t;
        for (int i = 0; i < 4; i++) {
            while (tCopy % primes[i] == 0) { tCopy /= primes[i]; requiredPower[i]++; }
        }
        if (tCopy != 1) return "-1";

        int length = num.size();
        array<int,10> minimalDigits = cheapestDigits(requiredPower);
        if (totalDigits(minimalDigits) > length) return buildString(minimalDigits);

        array<int,4> prefixPower = {0,0,0,0};
        for (int i = 0; i < length; i++) {
            int digit = num[i] - '0';
            for (int j = 0; j < 4; j++) prefixPower[j] += digitPrimePower[digit][j];
        }

        int firstZeroPosition = num.find('0');
        if (firstZeroPosition == (int)string::npos) {
            firstZeroPosition = length;
            if (coversRequirement(prefixPower, requiredPower)) return num;
        }

        for (int i = length - 1; i >= 0; i--) {
            int currentDigit = num[i] - '0';
            array<int,4> currentDigitPower = {
                digitPrimePower[currentDigit][0], digitPrimePower[currentDigit][1],
                digitPrimePower[currentDigit][2], digitPrimePower[currentDigit][3]
            };
            prefixPower = subtractPower(prefixPower, currentDigitPower);
            int spaceAfter = length - 1 - i;
            if (i > firstZeroPosition) continue;

            for (int candidate = currentDigit + 1; candidate <= 9; candidate++) {
                array<int,4> candidatePower = {
                    digitPrimePower[candidate][0], digitPrimePower[candidate][1],
                    digitPrimePower[candidate][2], digitPrimePower[candidate][3]
                };
                array<int,4> remainingPower = subtractPower(subtractPower(requiredPower, prefixPower), candidatePower);
                array<int,10> fillerDigits = cheapestDigits(remainingPower);
                if (totalDigits(fillerDigits) <= spaceAfter) {
                    int onesToFill = spaceAfter - totalDigits(fillerDigits);
                    return num.substr(0, i) + char('0' + candidate) + string(onesToFill, '1') + buildString(fillerDigits);
                }
            }
        }

        array<int,10> extendedDigits = cheapestDigits(requiredPower);
        return string(length + 1 - totalDigits(extendedDigits), '1') + buildString(extendedDigits);
    }
};