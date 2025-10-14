#include <iostream>
#include <string>

int main() {
    // 입출력 속도 향상 (선택 사항)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string word;
    std::cin >> word;

    int total_time = 0;

    for (char c : word) {
        switch (c) {
            case 'A': case 'B': case 'C':
                total_time += 3;
                break;
            case 'D': case 'E': case 'F':
                total_time += 4;
                break;
            case 'G': case 'H': case 'I':
                total_time += 5;
                break;
            case 'J': case 'K': case 'L':
                total_time += 6;
                break;
            case 'M': case 'N': case 'O':
                total_time += 7;
                break;
            case 'P': case 'Q': case 'R': case 'S':
                total_time += 8;
                break;
            case 'T': case 'U': case 'V':
                total_time += 9;
                break;
            case 'W': case 'X': case 'Y': case 'Z':
                total_time += 10;
                break;
        }
    }

    std::cout << total_time << std::endl;

    return 0;
}