#include <stdio.h>
#include "stack.h"

Stack copyStack(Stack s) {
    Stack temp, result;
    CreateEmpty(&temp);
    CreateEmpty(&result);
    
    while (!IsEmpty(s)) {
        int val;
        Pop(&s, &val);
        Push(&temp, val);
    }

    while (!IsEmpty(temp)) {
        int val;
        Pop(&temp, &val);
        Push(&s, val);
        Push(&result, val);
    }
    
    return result;
}

Stack reverseStack(Stack s) {
    Stack sResult, sTemp;
    CreateEmpty(&sResult);
    CreateEmpty(&sTemp);
    
    while (!IsEmpty(s)) {
        int topValue;
        Pop(&s, &topValue);
        Push(&sResult, topValue);
        Push(&sTemp, topValue);
    }
    
    while (!IsEmpty(sTemp)) {
        int topValue;
        Pop(&sTemp, &topValue);
        Push(&s, topValue);
    }

    return sResult;
}

int findMax(Stack s) {
    Stack temp = copyStack(s);
    int max = -1;
    
    if (!IsEmpty(temp)) {
        Pop(&temp, &max);
    }
    
    while (!IsEmpty(temp)) {
        int val;
        Pop(&temp, &val);
        if (val > max) {
            max = val;
        }
    }
    
    return max;
}

int main() {
    int N;
    scanf("%d", &N);

    Stack s;
    CreateEmpty(&s);

    for (int i = 0; i < N; i++) {
        int temp;
        scanf("%d", &temp);
        Push(&s, temp);
    }
    
    Stack sOriginal = copyStack(s);
    Stack sReverse = reverseStack(s);
    
    int leftWall = findMax(sReverse);
    int rightWall = findMax(s);
    
    int totalCapacity = 0;
    
    Stack leftStack = copyStack(sReverse);
    int currentLeftMax = 0;
    
    while (!IsEmpty(leftStack)) {
        int height;
        Pop(&leftStack, &height);
        
        if (height > currentLeftMax) {
            currentLeftMax = height;
        } else if (height < currentLeftMax) {
            totalCapacity += (currentLeftMax - height);
        }
    }

    Stack rightStack = copyStack(sOriginal);
    int currentRightMax = 0;
    
    while (!IsEmpty(rightStack)) {
        int height;
        Pop(&rightStack, &height);
        
        if (height > currentRightMax) {
            currentRightMax = height;
        } else if (height < currentRightMax) {
            totalCapacity += (currentRightMax - height);
        }
    }
    
    int minWall = leftWall < rightWall ? leftWall : rightWall;
    int correction = 0;
    
    Stack correctionStack = copyStack(sOriginal);
    while (!IsEmpty(correctionStack)) {
        int height;
        Pop(&correctionStack, &height);
        if (height < minWall) {
            correction += (minWall - height);
        }
    }
    
    totalCapacity -= correction;
    
    printf("%d\n", totalCapacity);

    return 0;
}