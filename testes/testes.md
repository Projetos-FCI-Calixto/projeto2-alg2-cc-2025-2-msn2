# Testes para ImageEncoder

> **Convenção usada nos arquivos PBM:**  
> `0` = branco → **B**  
> `1` = preto → **P**  
> `X` = região heterogênea → subdivisão

---

## 1. `border_frame_9x9.pbm`  
**Dimensões:** `9×9`  
**Código esperado:**

```
XXXXPPPBXPBXPBBXXPBXPBBBXXPBBXPBBBXXXPBXPBBBXXPBPBPBXBPBPXXXPBBXPBBBXXPBBPPXBBPPXBXBPBPXBBPPXBPPP
```

---

## 2. `checker_8x8.pbm`  
**Dimensões:** `8×8`  
**Código esperado:**

```
XXXBPPBXBPPBXBPPBXBPPBXXBPPBXBPPBXBPPBXBPPBXXBPPBXBPPBXBPPBXBPPBXXBPPBXBPPBXBPPBXBPPB
```

---

## 3. `diagonal_main_10x10.pbm`  
**Dimensões:** `10×10`  
**Código esperado:**

```
XXXXPBBPBBPBBXPBBPBBXXXPBBPBBPBBXPBBP
```

---

## 4. `horizontal_half_top_white_bottom_black_5x7.pbm`  
**Dimensões:** `5×7`  
**Código esperado:**

```
XBBPP
```

---

## 5. `letter_J_6x10.pbm`  
**Dimensões:** `6×10`  
**Código esperado:**

```
XBXXBPBPBXBPBPBXXXBPBBPXBPBBXXBPPBBBB
```

---

## 6. `quadrant_mosaic_11x11.pbm`  
**Dimensões:** `11×11`  
**Código esperado:**

```
XPBXXXBPPBXBPXBPBXXPBBPXPBXPBPXXPBPXBPBXXBPBXPBPXXXPBPBPXPBPXBPBPXXPBPXPBPXBPBP
```

---

## 7. `sparse_dots_13x9.pbm`  
**Dimensões:** `13×9`  
**Código esperado:**

```
XXXXPBBBXBBPBBBXXBPBBBXPBBXXBPBBXBPXBPBBXXXBBPBBBPXXPBBBXBPBBXBBXBPBXXBPBBBXXXPBBBXPBXXBPBBBXBBXBPBXXPBBBPXXBBXPBBXXPBBBPXBPBBXBBXBPB
```

---

## 8. `uniform_black_5x4.pbm`  
**Dimensões:** `5×4`  
**Código esperado:**

```
P
```

---

## 9. `uniform_white_5x4.pbm`  
**Dimensões:** `5×4`  
**Código esperado:**

```
B
```

---

## 10. `vertical_half_left_black_right_white_7x5.pbm`  
**Dimensões:** `7×5`  
**Código esperado:**

```
XPBPB
```
