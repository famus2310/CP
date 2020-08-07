<?php
function tofloat($val) {
  $val = str_replace(",",".",$val);
            $val = preg_replace('/\.(?=.*\.)/', '', $val);
            return floatval($val);
}

echo tofloat("8.15551,111");
