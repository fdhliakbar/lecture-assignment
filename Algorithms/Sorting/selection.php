<?php
    function selectionSort($arr) {
        $n = count($values);
        for ($i = 0; $i < $n-1; $i++) {
            $minIndex = $i;
            for ($j = $i+1; $j < $n; $j++) {
                if ($values[$j] < $values[$minIndex]) {
                    $minIndex = $j;
                }
            }
            $temp = $values[$i];
            $values[$i] = $values[$minIndex];
            $values[$minIndex] = $temp;
        }
        return $values;
    }
?>