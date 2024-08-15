﻿/*
 * Copyright (c) 2023~Now Margoo
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * \file vHTMLEscapeCharacter.cpp
 * \briefThe escape character in the HTML language for the VUILib HTML parser
 */

#include <include/parser/html/vHTMLEscapeCharacter.h>

std::unordered_map<OString, OString> HTMLEscapeCharacter = {
        {OString::from_utf16(u"¥"), "&#165;"},
        {OString::from_utf16(u"¥"), "&yen;"},
        {OString::from_utf16(u" "), "&#32;"},
        {OString::from_utf16(u" "), "&nbsp;"},
        {OString::from_utf16(u"<"), "&#60;"},
        {OString::from_utf16(u"<"), "&lt;"},
        {OString::from_utf16(u">"), "&#62;"},
        {OString::from_utf16(u">"), "&gt;"},
        {OString::from_utf16(u"&"), "&#38;"},
        {OString::from_utf16(u"&"), "&amp;"},
        {OString::from_utf16(u"\""), "&#34;"},
        {OString::from_utf16(u"\""), "&quot;"},
        {OString::from_utf16(u"'"), "&#39;"},
        {OString::from_utf16(u"'"), "&apos;"},
        {OString::from_utf16(u"¢"), "&#162;"},
        {OString::from_utf16(u"¢"), "&cent;"},
        {OString::from_utf16(u"£"), "&#163;"},
        {OString::from_utf16(u"£"), "&pound;"},
        {OString::from_utf16(u"¤"), "&#164;"},
        {OString::from_utf16(u"¤"), "&curren;"},
        {OString::from_utf16(u"¥"), "&#165;"},
        {OString::from_utf16(u"¥"), "&yen;"},
        {OString::from_utf16(u"¦"), "&#166;"},
        {OString::from_utf16(u"¦"), "&brvbar;"},
        {OString::from_utf16(u"§"), "&#167;"},
        {OString::from_utf16(u"§"), "&sect;"},
        {OString::from_utf16(u"¨"), "&#168;"},
        {OString::from_utf16(u"¨"), "&uml;"},
        {OString::from_utf16(u"©"), "&#169;"},
        {OString::from_utf16(u"©"), "&copy;"},
        {OString::from_utf16(u"ª"), "&#170;"},
        {OString::from_utf16(u"ª"), "&ordf;"},
        {OString::from_utf16(u"«"), "&#171;"},
        {OString::from_utf16(u"«"), "&laquo;"},
        {OString::from_utf16(u"¬"), "&#172;"},
        {OString::from_utf16(u"¬"), "&not;"},
        {OString::from_utf16(u"­"), "&#173;"},
        {OString::from_utf16(u"­"), "&shy;"},
        {OString::from_utf16(u"®"), "&#174;"},
        {OString::from_utf16(u"®"), "&reg;"},
        {OString::from_utf16(u"¯"), "&#175;"},
        {OString::from_utf16(u"¯"), "&macr;"},
        {OString::from_utf16(u"°"), "&#176;"},
        {OString::from_utf16(u"°"), "&deg;"},
        {OString::from_utf16(u"±"), "&#177;"},
        {OString::from_utf16(u"±"), "&plusmn;"},
        {OString::from_utf16(u"²"), "&#178;"},
        {OString::from_utf16(u"²"), "&sup2;"},
        {OString::from_utf16(u"³"), "&#179;"},
        {OString::from_utf16(u"³"), "&sup3;"},
        {OString::from_utf16(u"´"), "&#180;"},
        {OString::from_utf16(u"´"), "&acute;"},
        {OString::from_utf16(u"µ"), "&#181;"},
        {OString::from_utf16(u"µ"), "&micro;"},
        {OString::from_utf16(u"¶"), "&#182;"},
        {OString::from_utf16(u"¶"), "&para;"},
        {OString::from_utf16(u"·"), "&#183;"},
        {OString::from_utf16(u"·"), "&middot;"},
        {OString::from_utf16(u"¸"), "&#184;"},
        {OString::from_utf16(u"¸"), "&cedil;"},
        {OString::from_utf16(u"¹"), "&#185;"},
        {OString::from_utf16(u"¹"), "&sup1;"},
        {OString::from_utf16(u"º"), "&#186;"},
        {OString::from_utf16(u"º"), "&ordm;"},
        {OString::from_utf16(u"»"), "&#187;"},
        {OString::from_utf16(u"»"), "&raquo;"},
        {OString::from_utf16(u"¼"), "&#188;"},
        {OString::from_utf16(u"¼"), "&frac14;"},
        {OString::from_utf16(u"½"), "&#189;"},
        {OString::from_utf16(u"½"), "&frac12;"},
        {OString::from_utf16(u"¾"), "&#190;"},
        {OString::from_utf16(u"¾"), "&frac34;"},
        {OString::from_utf16(u"¿"), "&#191;"},
        {OString::from_utf16(u"¿"), "&iquest;"},
        {OString::from_utf16(u"À"), "&#192;"},
        {OString::from_utf16(u"À"), "&Agrave;"},
        {OString::from_utf16(u"Á"), "&#193;"},
        {OString::from_utf16(u"Á"), "&Aacute;"},
        {OString::from_utf16(u"Â"), "&#194;"},
        {OString::from_utf16(u"Â"), "&Acirc;"},
        {OString::from_utf16(u"Ã"), "&#195;"},
        {OString::from_utf16(u"Ã"), "&Atilde;"},
        {OString::from_utf16(u"Ä"), "&#196;"},
        {OString::from_utf16(u"Ä"), "&Auml;"},
        {OString::from_utf16(u"Å"), "&#197;"},
        {OString::from_utf16(u"Å"), "&Aring;"},
        {OString::from_utf16(u"Æ"), "&#198;"},
        {OString::from_utf16(u"Æ"), "&AElig;"},
        {OString::from_utf16(u"Ç"), "&#199;"},
        {OString::from_utf16(u"Ç"), "&Ccedil;"},
        {OString::from_utf16(u"È"), "&#200;"},
        {OString::from_utf16(u"È"), "&Egrave;"},
        {OString::from_utf16(u"É"), "&#201;"},
        {OString::from_utf16(u"É"), "&Eacute;"},
        {OString::from_utf16(u"Ê"), "&#202;"},
        {OString::from_utf16(u"Ê"), "&Ecirc;"},
        {OString::from_utf16(u"Ë"), "&#203;"},
        {OString::from_utf16(u"Ë"), "&Euml;"},
        {OString::from_utf16(u"Ì"), "&#204;"},
        {OString::from_utf16(u"Ì"), "&Igrave;"},
        {OString::from_utf16(u"Í"), "&#205;"},
        {OString::from_utf16(u"Í"), "&Iacute;"},
        {OString::from_utf16(u"Î"), "&#206;"},
        {OString::from_utf16(u"Î"), "&Icirc;"},
        {OString::from_utf16(u"Ï"), "&#207;"},
        {OString::from_utf16(u"Ï"), "&Iuml;"},
        {OString::from_utf16(u"Ð"), "&#208;"},
        {OString::from_utf16(u"Ð"), "&ETH;"},
        {OString::from_utf16(u"Ñ"), "&#209;"},
        {OString::from_utf16(u"Ñ"), "&Ntilde;"},
        {OString::from_utf16(u"Ò"), "&#210;"},
        {OString::from_utf16(u"Ò"), "&Ograve;"},
        {OString::from_utf16(u"Ó"), "&#211;"},
        {OString::from_utf16(u"Ó"), "&Oacute;"},
        {OString::from_utf16(u"Ô"), "&#212;"},
        {OString::from_utf16(u"Ô"), "&Ocirc;"},
        {OString::from_utf16(u"Õ"), "&#213;"},
        {OString::from_utf16(u"Õ"), "&Otilde;"},
        {OString::from_utf16(u"Ö"), "&#214;"},
        {OString::from_utf16(u"Ö"), "&Ouml;"},
        {OString::from_utf16(u"×"), "&#215;"},
        {OString::from_utf16(u"×"), "&times;"},
        {OString::from_utf16(u"Ø"), "&#216;"},
        {OString::from_utf16(u"Ø"), "&Oslash;"},
        {OString::from_utf16(u"Ù"), "&#217;"},
        {OString::from_utf16(u"Ù"), "&Ugrave;"},
        {OString::from_utf16(u"Ú"), "&#218;"},
        {OString::from_utf16(u"Ú"), "&Uacute;"},
        {OString::from_utf16(u"Û"), "&#219;"},
        {OString::from_utf16(u"Û"), "&Ucirc;"},
        {OString::from_utf16(u"Ü"), "&#220;"},
        {OString::from_utf16(u"Ü"), "&Uuml;"},
        {OString::from_utf16(u"Ý"), "&#221;"},
        {OString::from_utf16(u"Ý"), "&Yacute;"},
        {OString::from_utf16(u"Þ"), "&#222;"},
        {OString::from_utf16(u"Þ"), "&THORN;"},
        {OString::from_utf16(u"ß"), "&#223;"},
        {OString::from_utf16(u"ß"), "&szlig;"},
        {OString::from_utf16(u"à"), "&#224;"},
        {OString::from_utf16(u"à"), "&agrave;"},
        {OString::from_utf16(u"á"), "&#225;"},
        {OString::from_utf16(u"á"), "&aacute;"},
        {OString::from_utf16(u"â"), "&#226;"},
        {OString::from_utf16(u"â"), "&acirc;"},
        {OString::from_utf16(u"ã"), "&#227;"},
        {OString::from_utf16(u"ã"), "&atilde;"},
        {OString::from_utf16(u"ä"), "&#228;"},
        {OString::from_utf16(u"ä"), "&auml;"},
        {OString::from_utf16(u"å"), "&#229;"},
        {OString::from_utf16(u"å"), "&aring;"},
        {OString::from_utf16(u"æ"), "&#230;"},
        {OString::from_utf16(u"æ"), "&aelig;"},
        {OString::from_utf16(u"ç"), "&#231;"},
        {OString::from_utf16(u"ç"), "&ccedil;"},
        {OString::from_utf16(u"è"), "&#232;"},
        {OString::from_utf16(u"è"), "&egrave;"},
        {OString::from_utf16(u"é"), "&#233;"},
        {OString::from_utf16(u"é"), "&eacute;"},
        {OString::from_utf16(u"ê"), "&#234;"},
        {OString::from_utf16(u"ê"), "&ecirc;"},
        {OString::from_utf16(u"ë"), "&#235;"},
        {OString::from_utf16(u"ë"), "&euml;"},
        {OString::from_utf16(u"ì"), "&#236;"},
        {OString::from_utf16(u"ì"), "&igrave;"},
        {OString::from_utf16(u"í"), "&#237;"},
        {OString::from_utf16(u"í"), "&iacute;"},
        {OString::from_utf16(u"î"), "&#238;"},
        {OString::from_utf16(u"î"), "&icirc;"},
        {OString::from_utf16(u"ï"), "&#239;"},
        {OString::from_utf16(u"ï"), "&iuml;"},
        {OString::from_utf16(u"ð"), "&#240;"},
        {OString::from_utf16(u"ð"), "&eth;"},
        {OString::from_utf16(u"ñ"), "&#241;"},
        {OString::from_utf16(u"ñ"), "&ntilde;"},
        {OString::from_utf16(u"ò"), "&#242;"},
        {OString::from_utf16(u"ò"), "&ograve;"},
        {OString::from_utf16(u"ó"), "&#243;"},
        {OString::from_utf16(u"ó"), "&oacute;"},
        {OString::from_utf16(u"ô"), "&#244;"},
        {OString::from_utf16(u"ô"), "&ocirc;"},
        {OString::from_utf16(u"õ"), "&#245;"},
        {OString::from_utf16(u"õ"), "&otilde;"},
        {OString::from_utf16(u"ö"), "&#246;"},
        {OString::from_utf16(u"ö"), "&ouml;"},
        {OString::from_utf16(u"÷"), "&#247;"},
        {OString::from_utf16(u"÷"), "&divide;"},
        {OString::from_utf16(u"ø"), "&#248;"},
        {OString::from_utf16(u"ø"), "&oslash;"},
        {OString::from_utf16(u"ù"), "&#249;"},
        {OString::from_utf16(u"ù"), "&ugrave;"},
        {OString::from_utf16(u"ú"), "&#250;"},
        {OString::from_utf16(u"ú"), "&uacute;"},
        {OString::from_utf16(u"û"), "&#251;"},
        {OString::from_utf16(u"û"), "&ucirc;"},
        {OString::from_utf16(u"ü"), "&#252;"},
        {OString::from_utf16(u"ü"), "&uuml;"},
        {OString::from_utf16(u"ý"), "&#253;"},
        {OString::from_utf16(u"ý"), "&yacute;"},
        {OString::from_utf16(u"þ"), "&#254;"},
        {OString::from_utf16(u"þ"), "&thorn;"},
        {OString::from_utf16(u"ÿ"), "&#255;"},
        {OString::from_utf16(u"ÿ"), "&yuml;"},
        {OString::from_utf16(u"Α"), "&#913;"},
        {OString::from_utf16(u"Α"), "&Alpha;"},
        {OString::from_utf16(u"Β"), "&#914;"},
        {OString::from_utf16(u"Β"), "&Beta;"},
        {OString::from_utf16(u"Γ"), "&#915;"},
        {OString::from_utf16(u"Γ"), "&Gamma;"},
        {OString::from_utf16(u"Δ"), "&#916;"},
        {OString::from_utf16(u"Δ"), "&Delta;"},
        {OString::from_utf16(u"Ε"), "&#917;"},
        {OString::from_utf16(u"Ε"), "&Epsilon;"},
        {OString::from_utf16(u"Ζ"), "&#918;"},
        {OString::from_utf16(u"Ζ"), "&Zeta;"},
        {OString::from_utf16(u"Η"), "&#919;"},
        {OString::from_utf16(u"Η"), "&Eta;"},
        {OString::from_utf16(u"Θ"), "&#920;"},
        {OString::from_utf16(u"Θ"), "&Theta;"},
        {OString::from_utf16(u"Ι"), "&#921;"},
        {OString::from_utf16(u"Ι"), "&Iota;"},
        {OString::from_utf16(u"Κ"), "&#922;"},
        {OString::from_utf16(u"Κ"), "&Kappa;"},
        {OString::from_utf16(u"Λ"), "&#923;"},
        {OString::from_utf16(u"Λ"), "&Lambda;"},
        {OString::from_utf16(u"Μ"), "&#924;"},
        {OString::from_utf16(u"Μ"), "&Mu;"},
        {OString::from_utf16(u"Ν"), "&#925;"},
        {OString::from_utf16(u"Ν"), "&Nu;"},
        {OString::from_utf16(u"Ξ"), "&#926;"},
        {OString::from_utf16(u"Ξ"), "&Xi;"},
        {OString::from_utf16(u"Ο"), "&#927;"},
        {OString::from_utf16(u"Ο"), "&Omicron;"},
        {OString::from_utf16(u"Π"), "&#928;"},
        {OString::from_utf16(u"Π"), "&Pi;"},
        {OString::from_utf16(u"Ρ"), "&#929;"},
        {OString::from_utf16(u"Ρ"), "&Rho;"},
        {OString::from_utf16(u"Σ"), "&#931;"},
        {OString::from_utf16(u"Σ"), "&Sigma;"},
        {OString::from_utf16(u"Τ"), "&#932;"},
        {OString::from_utf16(u"Τ"), "&Tau;"},
        {OString::from_utf16(u"Υ"), "&#933;"},
        {OString::from_utf16(u"Υ"), "&Upsilon;"},
        {OString::from_utf16(u"Φ"), "&#934;"},
        {OString::from_utf16(u"Φ"), "&Phi;"},
        {OString::from_utf16(u"Χ"), "&#935;"},
        {OString::from_utf16(u"Χ"), "&Chi;"},
        {OString::from_utf16(u"Ψ"), "&#936;"},
        {OString::from_utf16(u"Ψ"), "&Psi;"},
        {OString::from_utf16(u"Ω"), "&#937;"},
        {OString::from_utf16(u"Ω"), "&Omega;"},
        {OString::from_utf16(u"α"), "&#945;"},
        {OString::from_utf16(u"α"), "&alpha;"},
        {OString::from_utf16(u"β"), "&#946;"},
        {OString::from_utf16(u"β"), "&beta;"},
        {OString::from_utf16(u"γ"), "&#947;"},
        {OString::from_utf16(u"γ"), "&gamma;"},
        {OString::from_utf16(u"δ"), "&#948;"},
        {OString::from_utf16(u"δ"), "&delta;"},
        {OString::from_utf16(u"ε"), "&#949;"},
        {OString::from_utf16(u"ε"), "&epsilon;"},
        {OString::from_utf16(u"ζ"), "&#950;"},
        {OString::from_utf16(u"ζ"), "&zeta;"},
        {OString::from_utf16(u"η"), "&#951;"},
        {OString::from_utf16(u"η"), "&eta;"},
        {OString::from_utf16(u"θ"), "&#952;"},
        {OString::from_utf16(u"θ"), "&theta;"},
        {OString::from_utf16(u"ι"), "&#953;"},
        {OString::from_utf16(u"ι"), "&iota;"},
        {OString::from_utf16(u"κ"), "&#954;"},
        {OString::from_utf16(u"κ"), "&kappa;"},
        {OString::from_utf16(u"λ"), "&#955;"},
        {OString::from_utf16(u"λ"), "&lambda;"},
        {OString::from_utf16(u"μ"), "&#956;"},
        {OString::from_utf16(u"μ"), "&mu;"},
        {OString::from_utf16(u"ν"), "&#957;"},
        {OString::from_utf16(u"ν"), "&nu;"},
        {OString::from_utf16(u"ξ"), "&#958;"},
        {OString::from_utf16(u"ξ"), "&xi;"},
        {OString::from_utf16(u"ο"), "&#959;"},
        {OString::from_utf16(u"ο"), "&omicron;"},
        {OString::from_utf16(u"π"), "&#960;"},
        {OString::from_utf16(u"π"), "&pi;"},
        {OString::from_utf16(u"ρ"), "&#961;"},
        {OString::from_utf16(u"ρ"), "&rho;"},
        {OString::from_utf16(u"ς"), "&#962;"},
        {OString::from_utf16(u"ς"), "&sigmaf;"},
        {OString::from_utf16(u"σ"), "&#963;"},
        {OString::from_utf16(u"σ"), "&sigma;"},
        {OString::from_utf16(u"τ"), "&#964;"},
        {OString::from_utf16(u"τ"), "&tau;"},
        {OString::from_utf16(u"υ"), "&#965;"},
        {OString::from_utf16(u"υ"), "&upsilon;"},
        {OString::from_utf16(u"φ"), "&#966;"},
        {OString::from_utf16(u"φ"), "&phi;"},
        {OString::from_utf16(u"χ"), "&#967;"},
        {OString::from_utf16(u"χ"), "&chi;"},
        {OString::from_utf16(u"ψ"), "&#968;"},
        {OString::from_utf16(u"ψ"), "&psi;"},
        {OString::from_utf16(u"ω"), "&#969;"},
        {OString::from_utf16(u"ω"), "&omega;"},
        {OString::from_utf16(u"∀"), "&#8704;"},
        {OString::from_utf16(u"∀"), "&forall;"},
        {OString::from_utf16(u"∂"), "&#8706;"},
        {OString::from_utf16(u"∂"), "&part;"},
        {OString::from_utf16(u"∃"), "&#8707;"},
        {OString::from_utf16(u"∃"), "&exist;"},
        {OString::from_utf16(u"∅"), "&#8709;"},
        {OString::from_utf16(u"∅"), "&empty;"},
        {OString::from_utf16(u"∇"), "&#8711;"},
        {OString::from_utf16(u"∇"), "&nabla;"},
        {OString::from_utf16(u"∈"), "&#8712;"},
        {OString::from_utf16(u"∈"), "&isin;"},
        {OString::from_utf16(u"∉"), "&#8713;"},
        {OString::from_utf16(u"∉"), "&notin;"},
        {OString::from_utf16(u"∋"), "&#8715;"},
        {OString::from_utf16(u"∋"), "&ni;"},
        {OString::from_utf16(u"∏"), "&#8719;"},
        {OString::from_utf16(u"∏"), "&prod;"},
        {OString::from_utf16(u"∑"), "&#8721;"},
        {OString::from_utf16(u"∑"), "&sum;"},
        {OString::from_utf16(u"−"), "&#8722;"},
        {OString::from_utf16(u"−"), "&minus;"},
        {OString::from_utf16(u"∗"), "&#8727;"},
        {OString::from_utf16(u"∗"), "&lowast;"},
        {OString::from_utf16(u"√"), "&#8730;"},
        {OString::from_utf16(u"√"), "&radic;"},
        {OString::from_utf16(u"∝"), "&#8733;"},
        {OString::from_utf16(u"∝"), "&prop;"},
        {OString::from_utf16(u"∞"), "&#8734;"},
        {OString::from_utf16(u"∞"), "&infin;"},
        {OString::from_utf16(u"∠"), "&#8736;"},
        {OString::from_utf16(u"∠"), "&ang;"},
        {OString::from_utf16(u"∧"), "&#8743;"},
        {OString::from_utf16(u"∧"), "&and;"},
        {OString::from_utf16(u"∨"), "&#8744;"},
        {OString::from_utf16(u"∨"), "&or;"},
        {OString::from_utf16(u"∩"), "&#8745;"},
        {OString::from_utf16(u"∩"), "&cap;"},
        {OString::from_utf16(u"∪"), "&#8746;"},
        {OString::from_utf16(u"∪"), "&cup;"},
        {OString::from_utf16(u"∫"), "&#8747;"},
        {OString::from_utf16(u"∫"), "&int;"},
        {OString::from_utf16(u"∴"), "&#8756;"},
        {OString::from_utf16(u"∴"), "&there4;"},
        {OString::from_utf16(u"∼"), "&#8764;"},
        {OString::from_utf16(u"∼"), "&sim;"},
        {OString::from_utf16(u"≅"), "&#8773;"},
        {OString::from_utf16(u"≅"), "&cong;"},
        {OString::from_utf16(u"≈"), "&#8776;"},
        {OString::from_utf16(u"≈"), "&asymp;"},
        {OString::from_utf16(u"≠"), "&#8800;"},
        {OString::from_utf16(u"≠"), "&ne;"},
        {OString::from_utf16(u"≡"), "&#8801;"},
        {OString::from_utf16(u"≡"), "&equiv;"},
        {OString::from_utf16(u"≤"), "&#8804;"},
        {OString::from_utf16(u"≤"), "&le;"},
        {OString::from_utf16(u"≥"), "&#8805;"},
        {OString::from_utf16(u"≥"), "&ge;"},
        {OString::from_utf16(u"⊂"), "&#8834;"},
        {OString::from_utf16(u"⊂"), "&sub;"},
        {OString::from_utf16(u"⊃"), "&#8835;"},
        {OString::from_utf16(u"⊃"), "&sup;"},
        {OString::from_utf16(u"⊄"), "&#8836;"},
        {OString::from_utf16(u"⊄"), "&nsub;"},
        {OString::from_utf16(u"⊆"), "&#8838;"},
        {OString::from_utf16(u"⊆"), "&sube;"},
        {OString::from_utf16(u"⊇"), "&#8839;"},
        {OString::from_utf16(u"⊇"), "&supe;"},
        {OString::from_utf16(u"⊕"), "&#8853;"},
        {OString::from_utf16(u"⊕"), "&oplus;"},
        {OString::from_utf16(u"⊗"), "&#8855;"},
        {OString::from_utf16(u"⊗"), "&otimes;"},
        {OString::from_utf16(u"⊥"), "&#8869;"},
        {OString::from_utf16(u"⊥"), "&perp;"},
        {OString::from_utf16(u"⋅"), "&#8901;"},
        {OString::from_utf16(u"⋅"), "&sdot;"},
        {OString::from_utf16(u"←"), "&#8592;"},
        {OString::from_utf16(u"←"), "&larr;"},
        {OString::from_utf16(u"↑"), "&#8593;"},
        {OString::from_utf16(u"↑"), "&uarr;"},
        {OString::from_utf16(u"→"), "&#8594;"},
        {OString::from_utf16(u"→"), "&rarr;"},
        {OString::from_utf16(u"↓"), "&#8595;"},
        {OString::from_utf16(u"↓"), "&darr;"},
        {OString::from_utf16(u"↔"), "&#8596;"},
        {OString::from_utf16(u"↔"), "&harr;"},
        {OString::from_utf16(u"↵"), "&#8629;"},
        {OString::from_utf16(u"↵"), "&crarr;"},
        {OString::from_utf16(u"⇐"), "&#8656;"},
        {OString::from_utf16(u"⇐"), "&lArr;"},
        {OString::from_utf16(u"⇑"), "&#8657;"},
        {OString::from_utf16(u"⇑"), "&uArr;"},
        {OString::from_utf16(u"⇒"), "&#8658;"},
        {OString::from_utf16(u"⇒"), "&rArr;"},
        {OString::from_utf16(u"⇓"), "&#8659;"},
        {OString::from_utf16(u"⇓"), "&dArr;"},
        {OString::from_utf16(u"⇔"), "&#8660;"},
        {OString::from_utf16(u"⇔"), "&hArr;"},
        {OString::from_utf16(u"¤"), "&#164;"},
        {OString::from_utf16(u"¤"), "&curren;"},
        {OString::from_utf16(u"¢"), "&#162;"},
        {OString::from_utf16(u"¢"), "&cent;"},
        {OString::from_utf16(u"£"), "&#163;"},
        {OString::from_utf16(u"£"), "&pound;"},
        {OString::from_utf16(u"€"), "&#8364;"},
        {OString::from_utf16(u"€"), "&euro;"},
        {OString::from_utf16(u"©"), "&#169;"},
        {OString::from_utf16(u"©"), "&copy;"},
        {OString::from_utf16(u"®"), "&#174;"},
        {OString::from_utf16(u"®"), "&reg;"},
        {OString::from_utf16(u"™"), "&#8482;"},
        {OString::from_utf16(u"™"), "&trade;"},
        {OString::from_utf16(u"§"), "&#167;"},
        {OString::from_utf16(u"§"), "&sect;"},
        {OString::from_utf16(u"¶"), "&#182;"},
        {OString::from_utf16(u"¶"), "&para;"},
        {OString::from_utf16(u"†"), "&#8224;"},
        {OString::from_utf16(u"†"), "&dagger;"},
        {OString::from_utf16(u"‡"), "&#8225;"},
        {OString::from_utf16(u"‡"), "&Dagger;"},
        {OString::from_utf16(u"•"), "&#8226;"},
        {OString::from_utf16(u"•"), "&bull;"},
        {OString::from_utf16(u"…"), "&#8230;"},
        {OString::from_utf16(u"…"), "&hellip;"},
        {OString::from_utf16(u"‰"), "&#8240;"},
        {OString::from_utf16(u"‰"), "&permil;"},
        {OString::from_utf16(u"‹"), "&#8249;"},
        {OString::from_utf16(u"‹"), "&lsaquo;"},
        {OString::from_utf16(u"›"), "&#8250;"},
        {OString::from_utf16(u"›"), "&rsaquo;"},
        {OString::from_utf16(u"‾"), "&#8254;"},
        {OString::from_utf16(u"‾"), "&oline;"},
        {OString::from_utf16(u"⁄"), "&#8260;"},
        {OString::from_utf16(u"⁄"), "&frasl;"},
        {OString::from_utf16(u"ℑ"), "&#8465;"},
        {OString::from_utf16(u"ℑ"), "&image;"},
        {OString::from_utf16(u"ℜ"), "&#8476;"},
        {OString::from_utf16(u"ℜ"), "&real;"}};

VHTMLInvalidEscapeCharacter::VHTMLInvalidEscapeCharacter(const OString &Character) {
	_info = ostr::format("VHTMLLexer Syntax Error : Invalid escape character \"{}\" .", Character);
	printf("%s", _info.c_str());
}

OString VHTMLEscapeMap::EscapeConvert(const OString &Character) {
	if (HTMLEscapeCharacter.contains(Character)) {
		return HTMLEscapeCharacter[Character];
	}
	else {
		throw VHTMLInvalidEscapeCharacter(Character);
	}

	return "";
}