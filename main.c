#include <stdio.h>
#include <stdlib.h>

void Input(double NCoef[], double DCoef[], int* NPower, int* DPower)
{
    int x ;
    printf("enter the degree of the numerator: ");
    scanf("%d", NPower);

    for (x = 0; x < *NPower; x++)
    {
        if (*NPower - x == 1)
        {
            printf("Enter the coefficient of X : ");
            scanf("%lf", &NCoef[x]);
        }
        else
        {
            printf("Enter the coefficient of X^%d : ", *NPower - x);
            scanf("%lf", &NCoef[x]);
        }
    }

    printf("Enter the constant term : ");
    scanf("%lf", &NCoef[x]);
    printf("enter the degree of the denominator: ");
    scanf("%d", DPower);

    for (x = 0; x < *DPower; x++)
    {
        if (*DPower - x == 1)
        {
            printf("Enter the coefficient of X : ");
            scanf("%lf", &DCoef[x]);
        }
        else
        {
            printf("Enter the coefficient of X^%d : ", *DPower - x);
            scanf("%lf", &DCoef[x]);
        }
    }
    printf("Enter the constant term : ");
    scanf("%lf", &DCoef[x]);
}

int Division(int NPower, int DPower)
{
    if (NPower >= DPower)
        {
            return 1;
        }
    else
    {
        return 0;
    }
}

int Divide(int NPower, double NCoef[], int DPower, double DCoef[], double outputCoef[])
{

    int outPower, i, j;
    double subtractionCoef[50];
    outPower = NPower - DPower;

    for (i = 0; i < NPower; i++)
    {
        if (Division(NPower - i, DPower))
        {
            outputCoef[i] = NCoef[i] / DCoef[0];
            for (j = 0; j <= DPower; j++)
            {
                subtractionCoef[j] = outputCoef[i] * DCoef[j];
            }
            for (j = 0; j <= DPower; j++)
            {
                NCoef[j + i] = NCoef[j + i] - subtractionCoef[j];
            }
        }
        else
            break;
    }
    return outPower;
}

void Poly(int outPower, double outCoef[])
{

    int p;
    char sign;

    printf("The output is : ");
    for (p = 0; p < outPower; p++)
    {
        if (outCoef[p] < 0)
        {
            outCoef[p] = -outCoef[p];
            sign = -1;
        }
        else if (outCoef[p] > 0)
            sign = 1;
        else
            continue;

        if (outCoef[p] == 1)
        {
            if (outPower - p == 1)
            {
                if (sign == 1)
                {
                    if (p == 0)
                        printf("X ");
                    else
                        printf("+ X ");
                }
                else if (sign == -1)
                {
                    if (p == 0)
                        printf("-X ");
                    else
                        printf("- X ");
                }
            }
            else
            {
                if (sign == 1)
                {
                      if (p == 0)
                      printf("X^%d ", outPower - p);
                      else
                      printf("+ X^%d ", outPower - p);
                }
                else if (sign == -1)
                {
                      if (p == 0)
                      printf("-X^%d ", outPower - p);
                      else
                      printf("- X^%d ", outPower - p);
                }
            }
        }
        else
        {
            if (outPower - p == 1)
            {
                if (p == 0)
                    printf("%0.2lfX ", sign * outCoef[p]);
                else if (sign == 1)
                    printf("+ %0.2lfX ", outCoef[p]);
                else if (sign == -1)
                    printf("- %0.2lfX ", outCoef[p]);
            }
            else
            {
                if (p == 0)
                    printf("%0.2lfX^%d ", sign * outCoef[p], outPower);
                else if (sign == 1)
                    printf("+ %0.2lfX^%d ", outCoef[p], outPower - p);
                else if (sign == -1)
                    printf("- %0.2lfX^%d ", outCoef[p], outPower - p);
            }
        }

    }
    if (!outPower)
        printf("%0.2lf ", outCoef[p]);
    else if (outCoef[p] > 0)
        printf("+ %0.2lf ", outCoef[p]);
    else if (outCoef[p] < 0)
        printf("- %0.2lf ", -outCoef[p]);

}

int Remain(int NPower, double NCoef[])
{
    int y;
    for (y= 0; y <= NPower; y++)
        if (NCoef[y])
            return 1;
    return 0;
}

void Remainder(int NPower, double NCoef[], int DPower, double DCoef[])
{
    int Z;
    char sign;
    for (Z = 0; Z <= NPower; Z++)
    {
        if (NCoef[Z])
        {
            if (NCoef[Z] > 0)
                sign = 1;
            else
            {
                sign = -1;
                NCoef[Z] = -NCoef[Z];
            }

            if (Z != 0 && !NCoef[Z - 1])
            {
                printf("+ (");
                if (NPower - Z == 0)
                {
                    if (sign == 1)
                        printf(" %0.2lf ", NCoef[Z]);
                    else if (sign == -1)
                        printf("- %0.2lf ", NCoef[Z]);
                }
                else if (NPower - Z == 1)
                {
                    if (sign == 1)
                        printf(" %0.2lfX ", NCoef[Z]);
                    else if (sign == -1)
                        printf("- %0.2lfX ", NCoef[Z]);
                }
                else if (NPower - Z > 1)
                {
                    if (sign == 1)
                        printf(" %0.2lfX^%d ", NCoef[Z], NPower - Z);
                    else if (sign == -1)
                        printf("- %0.2lfX^%d ", NCoef[Z], NPower - Z);
                }
            }
            else if (Z == 0)
            {
                printf("(");
                if (NPower - Z == 0)
                {
                    if (sign == 1)
                        printf(" %0.2lf ", NCoef[Z]);
                    else if (sign == -1)
                        printf("- %0.2lf ", NCoef[Z]);
                }
                else if (NPower - Z == 1)
                {
                    if (sign == 1)
                        printf(" %0.2lfX ", NCoef[Z]);
                    else if (sign == -1)
                        printf("- %0.2lfX ", NCoef[Z]);
                }
                else if (NPower - Z > 1)
                {
                    if (sign == 1)
                        printf(" %0.2lfX^%d ", NCoef[Z], NPower - Z);
                    else if (sign == -1)
                        printf("- %0.2lfX^%d ", NCoef[Z], NPower - Z);
                }
            }
            else
            {
                if (NPower - Z == 0)
                {
                    if (sign == 1)
                        printf("+ %0.2lf ", NCoef[Z]);
                    else if (sign == -1)
                        printf("- %0.2lf ", NCoef[Z]);
                }
                else if (NPower - Z == 1)
                {
                    if (sign == 1)
                        printf("+ %0.2lfX ", NCoef[Z]);
                    else if (sign == -1)
                        printf("- %0.2lfX ", NCoef[Z]);
                }
                else if (NPower - Z > 1)
                {
                    if (sign == 1)
                        printf("+ %0.2lfX^%d ", NCoef[Z], NPower - Z);
                    else if (sign == -1)
                        printf("- %0.2lfX^%d ", NCoef[Z], NPower - Z);
                }
            }
        }
    }
    printf(") / (");
    for (Z = 0; Z < DPower; Z++)
    {
        if (DCoef[Z] < 0)
        {
            DCoef[Z] = -DCoef[Z];
            sign = -1;
        }
        else if (DCoef[Z] > 0)
            sign = 1;
        else
            continue;

        if (DCoef[Z] == 1)
        {
            if (DPower - Z == 1)
            {
                if (Z == 0)
                    printf("X ");
                else
                    printf("+ X ");
            }
            else
            {
                if (Z == 0)
                    printf("X^%d ", DPower - Z);
                else
                    printf("+ X^%d ", DPower - Z);
            }
        }
        else if (DCoef[Z] == -1)
        {
            if (DPower - Z == 1)
            {
                printf("- X ");
            }
            else
            {
                printf("- X^%d ", DPower - Z);
            }
        }
        else
        {
            if (DPower - Z == 1)
            {
                if (Z == 0)
                    printf("%0.2lfX ", sign * DCoef[Z]);
                else if (sign == 1)
                    printf("+ %0.2lfX ", DCoef[Z]);
                else if (sign == -1)
                    printf("- %0.2lfX ", DCoef[Z]);
            }
            else
            {
                if (Z == 0)
                    printf("%0.2lfX^%d ", sign * DCoef[Z], DPower);
                else if (sign == 1)
                    printf("+ %0.2lfX^%d ", DCoef[Z], DPower - Z);
                else if (sign == -1)
                    printf("- %0.2lfX^%d ", DCoef[Z], DPower - Z);
            }
        }

    }
    if (DCoef[Z] > 0)
        printf("+ %0.2lf ", DCoef[Z]);
    else if (DCoef[Z] < 0)
        printf("- %0.2lf ", -DCoef[Z]);
    printf(")");
}

int main()
{
    double NCoef[50];
    double DCoef[50];
    double outCoef[50];
    int NPower, DPower, outPower;
    Input(NCoef, DCoef, &NPower, &DPower);
    if (Division(NPower, DPower))
    {
        outPower = Divide(NPower, NCoef, DPower, DCoef, outCoef);
        Poly(outPower, outCoef);
        if (Remain(NPower, NCoef))
            Remainder(NPower, NCoef, DPower, DCoef);
    }
    else
        Remainder(NPower, NCoef, DPower,DCoef);

}
