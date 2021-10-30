const char *A_PLUS = "4.3";
const char *A = "4";
const char *A_MINUS = "3.7";
const char *B_PLUS = "3.3";
const char *B = "3";
const char *B_MINUS = "2.7";
const char *C_PLUS = "2.3";
const char *C = "2";
const char *C_MINUS = "1.7";
const char *D_PLUS = "1.5";
const char *D = "1.3";
const char *D_MINUS = "1";
const char *F = "0";

int main(void) {
  int n;
  scanf("%d", &n);
  switch (n) {
    case 100:
    case 99:
    case 98:
    case 97:
    case 96:
    case 95:
      printf("%s\n", A_PLUS);
      break;
    case 94:
    case 93:
    case 92:
    case 91:
    case 90:
      printf("%s\n", A);
      break;
    case 89:
    case 88:
    case 87:
    case 86:
    case 85:
      printf("%s\n", A_MINUS);
      break;
    case 84:
    case 83:
    case 82:
      printf("%s\n", B_PLUS);
      break;
    case 81:
    case 80:
    case 79:
    case 78:
      printf("%s\n", B);
      break;
    case 77:
    case 76:
    case 75:
      printf("%s\n", B_MINUS);
      break;
    case 74:
    case 73:
    case 72:
      printf("%s\n", C_PLUS);
      break;
    case 71:
    case 70:
    case 69:
    case 68:
      printf("%s\n", C);
      break;
    case 67:
    case 66:
    case 65:
      printf("%s\n", C_MINUS);
      break;
    case 64:
      printf("%s\n", D_PLUS);
      break;
    case 63:
    case 62:
    case 61:
      printf("%s\n", D);
      break;
    case 60:
      printf("%s\n", D_MINUS);
      break;
    default:
      printf("%s\n", F);
  }
}
