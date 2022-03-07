package main
//fuck go语言貌似没有long long类型，这道题对数字大小太敏感了，用c++的那个
import (
	"fmt"
)

//获取最小公倍数
func getLCM(num1, num2 int64) int64 {
	return num1 * num2 / getGCM(num1, num2)

}

//获取最大公因数
func getGCM(num1, num2 int64) int64 {
	if num1 == num2 {
		return num1
	}
	if num1 < num2 {
		num1 ^= num2
		num2 ^= num1
		num1 ^= num2
	}
	var res int64 = num1 % num2
	for res > 0 {
		num1 = num2
		num2 = res
		res = num1 % num2
	}
	return num2
}

func abs(num int64) int64 {
	if num < 0 {
		return -1 * num
	}
	return num
}

func main() {
	//分子和分母
	var numerator, denominator []int64
	var i, n int64
	fmt.Scanln(&n)
	numerator = make([]int64, n)
	denominator = make([]int64, n)
	fmt.Scanf("%d/%d", &numerator[0], &denominator[0])
	var LCM int64 = denominator[0]
	for i = 1; i < n; i++ {
		fmt.Scanf("%d/%d", &numerator[i], &denominator[i])
		LCM = getLCM(denominator[i-1], denominator[i])
	}
	var sum, gcm int64
	for i = 0; i < n; i++ {
		sum += numerator[i] * LCM / denominator[i]
	}

	if sum == 0 {
		fmt.Println("0")
	} else {
		gcm = getGCM(abs(sum), LCM)
		sum /= gcm
		LCM /= gcm
		if sum/LCM == 0 {
			fmt.Printf("%d/%d\n", sum%LCM, LCM)
		} else {
			if LCM == 1 {
				fmt.Println(sum / LCM)
			} else {
				fmt.Printf("%d %d/%d\n", sum/LCM, sum%LCM, LCM)
			}
		}
	}
}
